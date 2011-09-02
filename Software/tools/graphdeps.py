#!/usr/bin/python
"""graphdeps V0.10
Copyright (c) 2011 Michael P. Hayes, UC ECE, NZ

Usage: graphdeps Makefile

Options:
    --outfile filename    filename of .dot outputfile

Examples:
"""

# This is a quick and dirty program.  It should be rewritten in
# an object-oriented manner.

import sys
import os
import re
from optparse import OptionParser


def parse_rules (filename):

    infile = open (filename, 'r')

    text = infile.read ()
    infile.close ()    

    # Look for targets ignoring targets starting with dot (.PHONY, etc).
    # This expects the command to be a single line.
    matches = re.findall (r'^([@a-z0-9._/\-]*):\s(.*)\n(.*)', text, re.MULTILINE)

    rules = []
    for match in matches:
        target = match[0]
        filename = None
        if '@' in target:
            (target, filename) = target.split ('@')
        # Target, dependencies, command, filename.
        rule = (target, match[1].strip().split (' '), match[2].strip (), filename)
        rules.append (rule)

    return rules


def node_output (dotfile, name, options):

    if options.debug:
        print >> sys.stderr, 'Node', name

    indirect = (name[0] == '@')
    if indirect:
        name = name[1:]

    if not options.calls and not options.fullpaths:
        name = os.path.basename (name)

    # Should check if creating a duplicate although graphviz will
    # weed them out.

    (file, ext) = os.path.splitext (name)

    cmap = {'.c' : 'green',
            '.h' : 'skyblue',
            '.o' : 'orange',
            '.out' : 'red'}

    colour = 'purple'
    if ext in cmap.keys ():
        colour = cmap[ext]

    shape = 'ellipse'
    if options.modules:
        colour = 'orange'
        shape = 'rectangle'

    if options.calls:
        colour = 'turquoise1'
        shape = 'rectangle'

    dotfile.write ('\t"' + name + '"\t [style=filled,shape=' + shape + ',color=' + colour + '];\n')

    return name


def op_output (dotfile, op, name):

    dotfile.write ('\t"' + op + '"\t[shape=rectangle,label="' + name + '"];\n')


def edge_output (dotfile, target, dep, indirect):

#    dotfile.write ('\t"' + target + '" ->\t"' + dep + '"\t[dir=back];\n')
    if indirect:
        dotfile.write ('\t"' + target + '" ->\t"' + dep + '"\t[style="dashed"];\n')
    else:
        dotfile.write ('\t"' + target + '" ->\t"' + dep + '";\n')


def dep_output (dotfile, target, dep, modules, options):

    if not options.calls and not options.fullpaths:
        dep = os.path.basename (dep)

    if options.debug:
        print >> sys.stderr, target, '::', dep

    if dep == '':
        return

    indirect = (dep[0] == '@')
    if indirect:
        dep = dep[1:]

    (file, ext) = os.path.splitext (target)        

    if not options.showops:
        edge_output (dotfile, target, dep, indirect)
    else:
        if ext == '.o':
            op = 'Compiler'
        elif ext == '.out':
            op = 'Linker'
        elif ext == '.hex':
            op = 'Objcopy'
        else:
            op = ''

        if op == '':
            edge_output (dotfile, target, dep, indirect)
        else:
            op_output (dotfile, op + target, op)
            edge_output (dotfile, target, op + target, indirect)
            edge_output (dotfile, op + target, dep, indirect)


def target_output (dotfile, target, targets, modules, options, seen = {}):

    if not target or seen.has_key (target):
        return
    deps = targets[target]

    if options.debug:
        print >> sys.stderr, target, ':', deps

    for dep in deps:
        if dep == '':
            continue
        if not targets.has_key (dep):
            node_output (dotfile, dep, options)
            
        if targets.has_key (dep) and target != dep:
            target_output (dotfile, dep, targets, modules, options, seen)
    
    target1 = node_output (dotfile, target, options)

    for dep in deps:
        if dep != '':
            dep_output (dotfile, target1, dep, modules, options)

    seen[target] = True



def main(argv = None):
    if argv is None:
        argv = sys.argv

    version = __doc__.split ('\n')[0]
    
    parser = OptionParser (usage = '%prog', version = version, 
                           description = __doc__)
    
    parser.add_option('--showops', action = 'store_true',
                      dest = 'showops', default = False,
                      help = 'show operations')

    parser.add_option('--modules', action = 'store_true',
                      dest = 'modules', default = False,
                      help = 'show module dependencies')

    parser.add_option('--calls', action = 'store_true',
                      dest = 'calls', default = False,
                      help = 'show callgraph')

    parser.add_option('--debug', action = 'store_true',
                      dest = 'debug', default = False,
                      help = 'enable debugging')

    parser.add_option('--fullpaths', action = 'store_true',
                      dest = 'fullpaths', default = False,
                      help = 'show full paths')

    parser.add_option('--outfile',  dest = 'outfilename',
                      default = 'graphdeps.dot',
                      help = 'output filename')

    parser.add_option('--target',  dest = 'target',
                      default = None,
                      help = 'target to start from; if unspecified all targets are displayed')

    (options, args) = parser.parse_args ()

    rules = parse_rules (args[0])

    cfiles = []
    hfiles = []
    for rule in rules:
        target = rule[0]
        (file, ext) = os.path.splitext (os.path.basename (target))
        if ext == '.o':
            cfiles.append (file + '.c')
        for dep in rule[1]:        
            (file, ext) = os.path.splitext (os.path.basename (dep))
            if ext == '.h':
                hfiles.append (file + '.h')

    modules = []
    for cfile in cfiles:
        (modname, ext) = os.path.splitext (cfile)
        hfile = modname + '.h'
        if hfile in hfiles and modname not in modules:
            modules.append (modname)

    targets = {}
    wantedtargets = []
    for rule in rules:
        target = rule[0]        
        targets[target] = rule[1]
        if options.target == None or target == options.target:
            wantedtargets.append (target)

    dopdf = options.outfilename[-4:] == '.pdf'
    dotfilename = options.outfilename
    if dopdf:
        dotfilename = '/tmp/tmp.dot'
            
    dotfile = open (dotfilename, 'w')
    dotfile.write ('strict digraph {\n\tgraph [rankdir=LR];\n')

    for target in wantedtargets:
        target_output (dotfile, target, targets, modules, options)

    if options.calls and options.modules:
        modules = {}
        for rule in rules:
            filename = rule[3]
            if not filename:
                continue
            if not modules.has_key (filename):
                modules[filename] = []
            modules[filename].append (rule[0])

        for module in modules.keys ():
            dotfile.write ('\tsubgraph "cluster_' + module + '" {label = "' + module + '";')
            for function in modules[module]:
                dotfile.write (function + ';')
            dotfile.write ('}\n')

    dotfile.write ('}\n')
    dotfile.close ()

    print ('Creating outfile ' + options.outfilename)

    if dopdf:
        os.system ('dot -T pdf -o ' + options.outfilename + ' ' + dotfilename)
        os.system ('rm ' + dotfilename)


if __name__ == '__main__':
    main()
