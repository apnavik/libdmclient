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
 * @file att_plugin_node_definition.h
 *
 * @brief
 * Interface to AT&T node definition for OMA-DM IMEI Sync
 *
 *****************************************************************************/

#if !defined(ATT_PLUGIN_NODE_DEFINITION_H)
#define ATT_PLUGIN_NODE_DEFINITION_H

#include<stdio.h>
#ifdef WIN32
#include "omadm_types.h"
#else
#include <stdbool.h>
#endif

#include <syncml_error.h>
#include <omadmtree_mo.h>
#include "att_plugin_common_defs.h"

#define STR_CASE_SENSITIVE_MASK 0x0000
#define STR_CASE_INSENSITIVE_MASK 0x0020

typedef union
{
	signed int *ivalue;
	char *cvalue;
	signed int *bvalue;
} typevalue;

typedef enum
{
	STORE_ONLY_TREE=0,
	STORE_TREE_CPSNVM=1,
	STORE_TREE_IMSNVM=2,
	STORE_TREE_DMACCNVM=3
} store_value_type;

void prv_free_node(plugin_node *node);

plugin_node * prv_find_subnode(plugin_node *node, const char *iURI,
					signed int exact);

plugin_node * prv_find_node(plugin_node *root,const char *iURI,
					signed int exact);

plugin_node * prv_create_node(plugin_node * parent,char * name);

void *get_nodetype_value(plugin_datatype data_type, char *leaf_value);

OmadmStrCmpErrType OmadmStrCaseCmp (const char *str1, const char *str2,
					OmadmStrCaseSensitivityEnum caseEnum);

signed int AttPluginInitFunc(char * iURI, char * iACL, char **file_ptr,
					void **oData);

signed int AttPluginMoSetFunc(const dmtree_node_t *nodeP, void *iData,
					store_value_type store_type);

plugin_datatype AttPluginGetNodeDataType(char *uri);

signed char AttPluginSetNodeDataType(const char * iURI,
					plugin_datatype datatype, void * iData);

signed int AttPluginMoSetDataType(const dmtree_node_t *nodeP, void *iData);

char * AttPluginReadPluginNodeValue(char *file_name, char *uri);

signed int AttPluginMoSetACL(const char *iURI, const char *iACL, void *iData);

signed int AttPluginSetDMAccNvmValues(void *iData);

void print_dm_tree(plugin_node *pl_node);

void AttPlugin_tree_close(void * iData);

char * str_cat_2(const char * first, const char * second);

char * str_cat_3(const char * first, const char * second, const char * third);

#endif  /*  !defined(ATT_PLUGIN_NODE_DEFINITION_H) */
