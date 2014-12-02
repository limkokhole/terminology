#ifndef _APP_SERVER_EET_H__
#define _APP_SERVER_EET_H__ 1

#include <Eina.h>
#include <Eet.h>

typedef struct _Term_Item Term_Item;
typedef struct _Terminology_Item Terminology_Item;

/* Term_Item */
Term_Item *term_item_new(const char * id, const char * dir);
void term_item_free(Term_Item *term_item);

void term_item_id_set(Term_Item *term_item, const char * id);
const char * term_item_id_get(const Term_Item *term_item);
void term_item_dir_set(Term_Item *term_item, const char * dir);
const char * term_item_dir_get(const Term_Item *term_item);

/* Terminology_Item */
Terminology_Item *terminology_item_new(unsigned int version);
void terminology_item_free(Terminology_Item *terminology_item);

void terminology_item_version_set(Terminology_Item *terminology_item, unsigned int version);
unsigned int terminology_item_version_get(const Terminology_Item *terminology_item);
void terminology_item_term_entries_add(Terminology_Item *terminology_item, const char * id, Term_Item *term_item);
void terminology_item_term_entries_del(Terminology_Item *terminology_item, const char * id);
Term_Item *terminology_item_term_entries_get(const Terminology_Item *terminology_item, const char * key);
Eina_Hash *terminology_item_term_entries_hash_get(const Terminology_Item *terminology_item);
void terminology_item_term_entries_modify(Terminology_Item *terminology_item, const char * key, void *value);

Terminology_Item *terminology_item_load(const char *filename);
Eina_Bool terminology_item_save(Terminology_Item *terminology_item, const char *filename);

/* Global initializer / shutdown functions */
void app_server_eet_init(void);
void app_server_eet_shutdown(void);

#endif /* _APP_SERVER_EET_H__ */