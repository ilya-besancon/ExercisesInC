/*
Created by Ilya Besancon

The purpose of this program is to read a text file,
split lines into words, and count the frequency of each word.

You should use Glib types, functions and data structures wherever
possible (and appropriate).  You should check the return values of all
function calls and handle errors appropriately.  You don't have to
free your data structures; we will work on that in a future exercise.
*/


#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <gio/gio.h> //for cancellables
//#include <glib-object.h>
#include <glib/gstdio.h> //for g_fopen



int main(int argc, char ** argv){
  const gchar *filename = argv[1];
  gchar *contents; // = get_contents();
  GError *err = NULL;
  gsize length;
  //g_file_get_contents (const gchar *filename, gchar **contents, gsize *length, GError **error);
  g_file_get_contents(filename, &contents, &length, &err);
  printf("Yay, the program runs!\n");

  //create a Hashtable for use:
  //GHashTable *g_hash_table_new (GHashFunc hash_func, GEqualFunc key_equal_func);
  GHashTable *mytable = g_hash_table_new(g_str_hash, g_str_equal); //exclude parentheses bcs not running functions here

  gchar *key;
  //gchar* value;
  g_hash_table_insert(mytable, g_strdup(key), 1);
  return 0;




  //OLD CODE
  //int g_open (const gchar *filename, int flags, int mode);
  //FILE *ptr = g_open("test.txt", "r");
  //char c[1000];
  //FILE *ptr = g_fopen(argv[1], "r");
  //char * g_data_input_stream_read_line (GDataInputStream *stream, gsize *length, GCancellable *cancellable, GError **error);
  //gchar *contents;
  //GCancellable *thing = g_cancellable_new (void);

  //char *input = g_data_input_stream_read_line(ptr, &length, NULL, &err);

  //printf("Printing: %s\n", input);
  //fscanf(ptr,"%[^\n]", c);

  //printf("Data from the file: \n %s\n", c);
  //fclose(fptr);
}
