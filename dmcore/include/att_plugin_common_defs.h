/*
 * libdmclient
 *
 * Copyright (C) 2019 Intel Corporation. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Ankit P. Navik <ankit.p.navik@intel.com>
 *
 */

/*!
 * @file att_plugin_common_defs.h
 *
 * @brief
 * Macros to help with AT&T common constants for OMA-DM IMEI Sync
 *
 *****************************************************************************/

#if !defined(ATT_PLUGIN_COMMON_DEFS_H)
#define ATT_PLUGIN_COMMON_DEFS_H

#ifndef NULL		/* a NULL pointer */
#define NULL (void*) 0
#endif

#ifndef FALSE
#define FALSE	0
#endif

#ifndef TRUE
#define TRUE	1
#endif

enum
{
	ODIS_SUCCESS=0,
	ODIS_FAILURE=1
};

/**
 *	Enum definiton for Plugin Node Type
 */

typedef enum plugin_datatype_t
{
	OMADM_NODE_TYPE_NONE,
	OMADM_NODE_TYPE_NODE,
	OMADM_NODE_TYPE_INT,
	OMADM_NODE_TYPE_CHAR,
	OMADM_NODE_TYPE_BOOL
} plugin_datatype;

/**
 *	Structure definiton for Plugin Node
 */

typedef struct plugin_node_t
{
	char * uri;
	char * urn;
	char * name;
	omadmtree_node_kind_t type;
	char * acl;
	plugin_datatype datatype;
	char * value;
	dmtree_node_t * content;
	struct plugin_node_t * children;
	struct plugin_node_t * next;
	struct plugin_node_t * parent;
} plugin_node;

typedef enum OmadmStrCaseSensitivityEnum_t
{
	OMADM_STR_CASE_SENSITIVE,
	OMADM_STR_CASE_INSENSITIVE
} OmadmStrCaseSensitivityEnum;

typedef enum OmadmStrCmpErrType_t
{
	OMADM_STRCMP_ERR   = -2,
	OMADM_STRCMP_LOWER = -1,
	OMADM_STRCMP_EQUAL =  0,
	OMADM_STRCMP_UPPER =  1
} OmadmStrCmpErrType;

#endif  /* !defined(ATT_PLUGIN_COMMON_DEFS_H) */
