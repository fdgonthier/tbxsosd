/**
 * tbxsosd/libdb/ldapdb_utils.h
 * Copyright (C) 2006-2012 Opersys inc.
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
 * Misc LDAP functions that don't fit anywhere else.
 * @author: François-Denis Gonthier
 */

#ifndef _LDAPDB_UTILS_H
#define _LDAPDB_UTILS_H

void kdldap_paranoid_push_error(LDAP *ldap_conn, int ldap_err);

char *kdldap_escape_string(apr_pool_t *pool, const char *src, size_t src_sz);

#endif // _LDAPDB_UTILS_H_
