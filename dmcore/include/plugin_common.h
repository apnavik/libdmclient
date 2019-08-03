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
 * Macros to help with plugin common for OMA-DM
 *
 *****************************************************************************/

#if !defined(PLUGIN_COMMON_H)
#define PLUGIN_COMMON_H

#include "att_plugin_common_defs.h"

#define  CB_OP_INIT	0x01
#define  CB_OP_READ	0x02
#define  CB_OP_WRITE	0x04
#define  CB_OP_NOTIFY	0x08
#define  CB_OP_EXEC	0x10

#define CB_OP_MASK	0xff
#define CB_OP_SET(target, opFlag)	(target |=  opFlag)
#define CB_OP_CLEAR(target, opFlag)	(target &= ~opFlag)
#define CB_OP_ISSET(target, opFlag)	(target & opFlag)

/**
 *	Enum definiton for Call Back functions return type
 */
typedef enum configCbReturnType_t
{
	VALUE_STORAGE_ERROR = 0,
	VALUE_STORAGE_SUPPORTED,
	VALUE_STORAGE_NOT_SUPPORTED
} configCbReturnType;

typedef signed int pluginConfigGetCb(unsigned char cbOpFlag,
					dmtree_node_t *node, void * value);

typedef signed int pluginConfigSetCb(unsigned char cbOpFlag,
					const dmtree_node_t *node, void * value);

/**
 *	Structure definiton for Registation of Plugin
 */
typedef struct RegisterPluginEntry_t
{
	char * pluginUri;
	pluginConfigGetCb * configCbGetFunc;
	pluginConfigSetCb * configCbSetFunc;
	char cbOpFlags;
	void * pRootNode;
} RegisterPluginEntry;

/**
 *	Structure definiton for Registation of Plugin Entry List
 */
struct RegisterPluginListEntry
{
	RegisterPluginEntry regPluginEntry;
	struct RegisterPluginListEntry * next;
};

signed int ConfigRepositoryUpdateConfigData(char *file_name1, char *value2find,
					char *value2repl, char *uri);

signed int ConfigRepositoryProcessGetCommand(unsigned char op,
					dmtree_node_t *node, void * root);

signed int ConfigRepositoryProcessSetCommand(unsigned char op,
					const dmtree_node_t *node, void * root);

plugin_datatype ConfigRepositoryReadNodeDataType(char *uri);

RegisterPluginEntry * getpluginEntry(char * uri);

RegisterPluginEntry* register_plugin(RegisterPluginEntry pluginEntry);

signed int ConfigRepositoryCreatePluginConfigFiles(char ** pluginConfigArray,
					char * file_name);

#endif /* PLUGIN_COMMON_H */
