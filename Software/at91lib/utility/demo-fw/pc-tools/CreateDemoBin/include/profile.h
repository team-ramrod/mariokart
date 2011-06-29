/*
 * profile.h
 *
 *  Created on: Oct 26, 2009
 *      Author: Tony.Liu
 */

#ifndef PROFILE_H_
#define PROFILE_H_

#include "CreateDemoBin.h"

typedef struct {
	char *pProfileName;
	BMPConvOpt options;
} Profile;

static Profile profile[] = {
		{"at91sam3u-ek", {16, 320, 240, 270, 1}}
};

#endif /* PROFILE_H_ */
