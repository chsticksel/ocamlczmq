/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#include "QmlZhash.h"


///
//  Insert item into hash table with specified key and item.               
//  If key is already present returns -1 and leaves existing item unchanged
//  Returns 0 on success.                                                  
int QmlZhash::insert (const QString &key, void *item) {
    return zhash_insert (self, key.toUtf8().data(), item);
};

///
//  Update item into hash table with specified key and item.            
//  If key is already present, destroys old item and inserts new one.   
//  Use free_fn method to ensure deallocator is properly called on item.
void QmlZhash::update (const QString &key, void *item) {
    zhash_update (self, key.toUtf8().data(), item);
};

///
//  Remove an item specified by key from the hash table. If there was no such
//  item, this function does nothing.                                        
void QmlZhash::delete (const QString &key) {
    zhash_delete (self, key.toUtf8().data());
};

///
//  Return the item at the specified key, or null
void *QmlZhash::lookup (const QString &key) {
    return zhash_lookup (self, key.toUtf8().data());
};

///
//  Reindexes an item from an old key to a new key. If there was no such
//  item, does nothing. Returns 0 if successful, else -1.               
int QmlZhash::rename (const QString &oldKey, const QString &newKey) {
    return zhash_rename (self, oldKey.toUtf8().data(), newKey.toUtf8().data());
};

///
//  Set a free function for the specified hash table item. When the item is
//  destroyed, the free function, if any, is called on that item.          
//  Use this when hash items are dynamically allocated, to ensure that     
//  you don't have memory leaks. You can pass 'free' or NULL as a free_fn. 
//  Returns the item, or NULL if there is no such item.                    
void *QmlZhash::freefn (const QString &key, zhash_free_fn freeFn) {
    return zhash_freefn (self, key.toUtf8().data(), freeFn);
};

///
//  Return the number of keys/items in the hash table
size_t QmlZhash::size () {
    return zhash_size (self);
};

///
//  Make copy of hash table; if supplied table is null, returns null.    
//  Does not copy items themselves. Rebuilds new table so may be slow on 
//  very large tables. NOTE: only works with item values that are strings
//  since there's no other way to know how to duplicate the item value.  
QmlZhash *QmlZhash::dup () {
    QmlZhash *retQ_ = new QmlZhash ();
    retQ_->self = zhash_dup (self);
    return retQ_;
};

///
//  Return keys for items in table
QmlZlist *QmlZhash::keys () {
    QmlZlist *retQ_ = new QmlZlist ();
    retQ_->self = zhash_keys (self);
    return retQ_;
};

///
//  Simple iterator; returns first item in hash table, in no given order, 
//  or NULL if the table is empty. This method is simpler to use than the 
//  foreach() method, which is deprecated. To access the key for this item
//  use zhash_cursor(). NOTE: do NOT modify the table while iterating.    
void *QmlZhash::first () {
    return zhash_first (self);
};

///
//  Simple iterator; returns next item in hash table, in no given order, 
//  or NULL if the last item was already returned. Use this together with
//  zhash_first() to process all items in a hash table. If you need the  
//  items in sorted order, use zhash_keys() and then zlist_sort(). To    
//  access the key for this item use zhash_cursor(). NOTE: do NOT modify 
//  the table while iterating.                                           
void *QmlZhash::next () {
    return zhash_next (self);
};

///
//  After a successful first/next method, returns the key for the item that
//  was returned. This is a constant string that you may not modify or     
//  deallocate, and which lasts as long as the item in the hash. After an  
//  unsuccessful first/next, returns NULL.                                 
const QString QmlZhash::cursor () {
    return QString (zhash_cursor (self));
};

///
//  Add a comment to hash table before saving to disk. You can add as many   
//  comment lines as you like. These comment lines are discarded when loading
//  the file. If you use a null format, all comments are deleted.            
void QmlZhash::comment (const QString &format) {
    zhash_comment (self, "%s", format.toUtf8().data());
};

///
//  Serialize hash table to a binary frame that can be sent in a message.
//  The packed format is compatible with the 'dictionary' type defined in
//  http://rfc.zeromq.org/spec:35/FILEMQ, and implemented by zproto:     
//                                                                       
//     ; A list of name/value pairs                                      
//     dictionary      = dict-count *( dict-name dict-value )            
//     dict-count      = number-4                                        
//     dict-value      = longstr                                         
//     dict-name       = string                                          
//                                                                       
//     ; Strings are always length + text contents                       
//     longstr         = number-4 *VCHAR                                 
//     string          = number-1 *VCHAR                                 
//                                                                       
//     ; Numbers are unsigned integers in network byte order             
//     number-1        = 1OCTET                                          
//     number-4        = 4OCTET                                          
//                                                                       
//  Comments are not included in the packed data. Item values MUST be    
//  strings.                                                             
QmlZframe *QmlZhash::pack () {
    QmlZframe *retQ_ = new QmlZframe ();
    retQ_->self = zhash_pack (self);
    return retQ_;
};

///
//  Save hash table to a text file in name=value format. Hash values must be
//  printable strings; keys may not contain '=' character. Returns 0 if OK, 
//  else -1 if a file error occurred.                                       
int QmlZhash::save (const QString &filename) {
    return zhash_save (self, filename.toUtf8().data());
};

///
//  Load hash table from a text file in name=value format; hash table must 
//  already exist. Hash values must printable strings; keys may not contain
//  '=' character. Returns 0 if OK, else -1 if a file was not readable.    
int QmlZhash::load (const QString &filename) {
    return zhash_load (self, filename.toUtf8().data());
};

///
//  When a hash table was loaded from a file by zhash_load, this method will
//  reload the file if it has been modified since, and is "stable", i.e. not
//  still changing. Returns 0 if OK, -1 if there was an error reloading the 
//  file.                                                                   
int QmlZhash::refresh () {
    return zhash_refresh (self);
};

///
//  Set hash for automatic value destruction
void QmlZhash::autofree () {
    zhash_autofree (self);
};

///
//  DEPRECATED as clumsy -- use zhash_first/_next instead                  
//  Apply function to each item in the hash table. Items are iterated in no
//  defined order. Stops if callback function returns non-zero and returns 
//  final return code from callback function (zero = success).             
//  Callback function for zhash_foreach method                             
int QmlZhash::foreach (zhash_foreach_fn callback, void *argument) {
    return zhash_foreach (self, callback, argument);
};


QObject* QmlZhash::qmlAttachedProperties(QObject* object) {
    return new QmlZhashAttached(object);
}


///
//  Unpack binary frame into a new hash table. Packed data must follow format
//  defined by zhash_pack. Hash table is set to autofree. An empty frame     
//  unpacks to an empty hash table.                                          
QmlZhash *QmlZhashAttached::unpack (QmlZframe *frame) {
    QmlZhash *retQ_ = new QmlZhash ();
    retQ_->self = zhash_unpack (frame->self);
    return retQ_;
};

///
//  Self test of this class.
void QmlZhashAttached::test (bool verbose) {
    zhash_test (verbose);
};

///
//  Create a new, empty hash container
QmlZhash *QmlZhashAttached::construct () {
    QmlZhash *qmlSelf = new QmlZhash ();
    qmlSelf->self = zhash_new ();
    return qmlSelf;
};

///
//  Destroy a hash container and all items in it
void QmlZhashAttached::destruct (QmlZhash *qmlSelf) {
    zhash_destroy (&qmlSelf->self);
};

/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
