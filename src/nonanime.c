#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <assert.h>
#include <unistd.h>
//#include "global.h"
//#include "nonanime/nonanime.global.h"
//#include "nonanime/nonanime.parser.h"
//#include "objnonanime.hpp"
#include "nonanime.h"
#include "nonanime.global.h"
//#include "nonanime.parser.h"
#include "nonanime.parser.tab.h"

#define SUFF_NONANIMEOUT ".lexing.out"

extern FILE *yynonanimein;
extern FILE *yynonanimeout;
extern int yynonanimeparse(void);


nonanime_t * nonanime_make(void) {
  nonanime_t * this = NULL; 
  this = (nonanime_t *) malloc(sizeof(*this)); 
  bzero(this, sizeof(*this)); 
  return this; 
}; 

void nonanime_delete(nonanime_t * this) {
  free(this); 
}; 

nonanime_t * nonanime_make_from_file(const char * filename, const char * log_filename) {
  MALLOC_BZERO(nonanime_t,this); 
  const int retval = nonanime__fill_from_file(this, filename, log_filename); 
  if (retval < 0) { 
    free(this); 
    return NULL; 
  }; 
  return this; 
}; 



void nonanime__actions_push(nonanime_t * this, const char * actions_nom, const int actions_menu_huh, const char * actions_affichage, const char * actions_icone, const char * actions_gestionnaire_fichier, const char * actions_gestionnaire_proc) {
  assert(this -> actions_nb < nonanime_actions_size); 
  
  const int action_i = this -> actions_nb; 
  this -> actions_array_nom[action_i] = strcopy(actions_nom); 
  this -> actions_array_menu[action_i] = actions_menu_huh; 
  this -> actions_array_affichage[action_i] = strcopy(actions_affichage); 
  this -> actions_array_icone[action_i] = strcopy(actions_icone); 
  this -> actions_array_gestionnaire_fichier[action_i] = strcopy(actions_gestionnaire_fichier); 
  this -> actions_array_gestionnaire_proc[action_i] = strcopy(actions_gestionnaire_proc); 
  
  this -> actions_nb ++; 
}; 

void nonanime__events_push(nonanime_t * this, const char * events_nom, const int events_genere_type, const char * events_genere_code_fichier, const char * events_genere_code_proc, const char * events_traitement_fichier, const char * events_traitement_proc) {
  assert(this -> events_nb < nonanime_events_size); 
  
  const int action_i = this -> events_nb; 
  this -> events_array_nom[action_i] = strcopy(events_nom); 
  this -> events_array_genere_type[action_i] = events_genere_type; 
  this -> events_array_genere_code_fichier[action_i] = strcopy(events_genere_code_fichier); 
  this -> events_array_genere_code_proc[action_i] = strcopy(events_genere_code_proc); 
  this -> events_array_traitement_code_fichier[action_i] = strcopy(events_traitement_fichier); 
  this -> events_array_traitement_code_proc[action_i] = strcopy(events_traitement_proc); 
  
  this -> events_nb ++; 
}; 

void nonanime__elements_push(nonanime_t * this, const char * elements_nom, const char * elements_image) {
  assert(this -> elements_nb < nonanime_elements_size); 
  
  const int action_i = this -> elements_nb; 
  this -> elements_nom[action_i] = strcopy(elements_nom); 
  this -> elements_image[action_i] = strcopy(elements_image); 
  
  this -> elements_nb ++; 
}; 





void nonanime__print(const nonanime_t * this, FILE * out_stream) { 
  //fprintf(out_stream, "filename = '%s'" "\n", NULL); 
  fprintf(out_stream, "filename = '%s'" "\n", this -> filename); 
  
  fprintf(out_stream, " " "\n"); 
  
  fprintf(out_stream, "physique { " "\n"); 
  fprintf(out_stream, "\t" "choc_longueur  = %f" "\n", this -> choc_longueur); 
  fprintf(out_stream, "\t" "choc_largeur   = %f" "\n", this -> choc_largeur); 
  fprintf(out_stream, "\t" "choc_hauteur   = %f" "\n", this -> choc_hauteur); 
  fprintf(out_stream, "\t" "masse          = %f" "\n", this -> masse); 
  fprintf(out_stream, "\t" "compressible   = %d" "\n", this -> compressible); 
  fprintf(out_stream, "\t" "fixe           = %d" "\n", this -> fixe); 
  fprintf(out_stream, "\t" "rebondissement = %f" "\n", this -> rebondissement); 
  fprintf(out_stream, "}; " "\n"); 
  
  fprintf(out_stream, " " "\n"); 
  
  fprintf(out_stream, "gameplay { " "\n"); 
  fprintf(out_stream, "\t" "vie        = %d" "\n", this -> vie); 
  fprintf(out_stream, "\t" "invincible = %d" "\n", this -> invincible); 
  fprintf(out_stream, "}; " "\n"); 
  
  fprintf(out_stream, " " "\n"); 
  


  fprintf(out_stream, "graphique { " "\n"); 

  { 
    fprintf(out_stream, "\t" " " "\n"); 
    fprintf(out_stream, "\t" "elements[%d] =  " "\n", this -> elements_nb); 
    for (int i = 0; i < this -> elements_nb; i++) { 
      fprintf(out_stream, "\t" "\t" "{ nom = %s \t\t ; image := %s \t\t ; racine := %s \t\t ;}," "\n", this -> elements_nom[i], this -> elements_image[i], this -> racines[i]); 
    }; 
    fprintf(out_stream, "\t" "; " "\n"); 
  }; 

  { 
    fprintf(out_stream, "\t" " " "\n"); 
    fprintf(out_stream, "\t" "actions[%d] =  " "\n", this -> actions_nb); 
    for (int i = 0; i < this -> actions_nb; i++) { 
      fprintf(out_stream, "\t" "\t" "{ nom = %s \t\t ; menu := %3d ; affichage := %s \t\t ; icone := %s \t\t ; fichier := %s \t\t ; proc = %s \t\t ;}," "\n", this -> actions_array_nom[i], this -> actions_array_menu[i], this -> actions_array_affichage[i], this -> actions_array_icone[i], this -> actions_array_gestionnaire_fichier[i], this -> actions_array_gestionnaire_proc[i]); 
    }; 
    fprintf(out_stream, "\t" "; " "\n"); 
  }; 

  { 
    fprintf(out_stream, "\t" " " "\n"); 
    fprintf(out_stream, "\t" "events[%d] =  " "\n", this -> events_nb); 
    for (int i = 0; i < this -> events_nb; i++) { 
      fprintf(out_stream, "\t" "\t" "{ nom = %s \t\t ; type := %3d ; raise_fichier := %s \t\t ; raise_code := %s \t\t ; process_fichier := %s \t\t ; process_proc = %s \t\t ;}," "\n", this -> events_array_nom[i], this -> events_array_genere_type[i], this -> events_array_genere_code_fichier[i], this -> events_array_genere_code_proc[i], this -> events_array_traitement_code_fichier[i], this -> events_array_traitement_code_proc[i]); 
    }; 
    fprintf(out_stream, "\t" "; " "\n"); 
  }; 

  fprintf(out_stream, "}; " "\n"); 

  fprintf(out_stream, " " "\n"); 


  
  
}; 










int nonanime__fill_from_file(nonanime_t * this, const char * filename, const char * log_filename) {
  if (filename == NULL) { nonanime_err("Erreur: impossible 'filename' est le pointeur NULL.\n"); return -1; }; 
  
#if 1 
  this -> filename = nonanime_strcopy(filename); 
#else 
  { 
    const char * cstr = filename; 
    char * copy_cstr = NULL; 
    { 
      //return NULL; 
      //fprintf(stderr_FILE, "{" __FILE__ ":" BIGLIB_STRING(__LINE__) ":<%s()>}: " " cstr = %p "   "\n", __func__, cstr); 
      //fprintf(stderr_FILE, " cstr = %p "   "\n", cstr); 
      //dprintf(2, " cstr = %p "   "\n", cstr); 
      //dprintf(2, " cstr =  "   "\n"); 
      copy_cstr ++; 
      copy_cstr ++; 
      copy_cstr ++; 
      copy_cstr ++; 
      copy_cstr += 8; 
      char a[] = "ALK\n"; 
      copy_cstr = a;
      write(2, "ALK\n", 4); 
      if (cstr == NULL) return -1; 
      //const int cstr_len = strlen(cstr); 
      const char * p = cstr; while (*p) p++; 
      const int cstr_len = p - cstr; 
      const int byte_size = (cstr_len+1) * (sizeof(char)); 
      //char * copy_cstr = malloc(byte_size); 
      copy_cstr = malloc(byte_size); 
      //return strcpy(copy_cstr, cstr); 
      //bcopy(cstr, copy_cstr, byte_size); 
      char * q = copy_cstr; 
      p = cstr; 
      for (;;) { *q = *p; if (!*p) break; q++; p++; }; 
      //return copy_cstr; 
    }; 
    this -> filename = copy_cstr; 
  }; 
#endif 
  
  // log file 
  if (NULL == log_filename) { 
    char nonanime_log[strlen(filename) + strlen(SUFF_NONANIMEOUT) + 1];
    strcat(strcpy(nonanime_log, filename), SUFF_NONANIMEOUT);
    //message("On essaye d'ouvrir en lecture le fichier '%s'.", nonanime_log);
    yynonanimeout = fopen(nonanime_log, "wb");
    if (yynonanimeout == NULL) {
      nonanime_err("Erreur: impossible d'ouvrir en écriture le fichier \"%s\".\n", nonanime_log);
      return -2;
    };
  }  
  else {
    //message("On essaye d'ouvrir en écriture le fichier '%s'." "\n", log_filename);
    yynonanimeout = fopen(log_filename, "wb");
    if (yynonanimeout == NULL) {
      nonanime_err("Erreur: impossible d'ouvrir en écriture le fichier \"%s\".\n", log_filename);
      return -3;
    }; 
  };
  
  
  //yynonanimein
  FILE * entrin = NULL;
  { 
#if 0 
    char nonanime_fullpath[strlen(filename) + strlen(dir) + 1];
    nonanime_fullpath = strcat(strcpy(nonanime_fullpath, dir), filename);
#else 
    const char * nonanime_fullpath = filename; 
#endif 
    entrin = fopen(nonanime_fullpath, "rb");
    if (entrin == NULL) {
      nonanime_err("Erreur : impossible d'ouvrir en lecture le fichier \"%s\".\n", filename);
      (void) fclose(yynonanimeout);
      return -4;
    }; 
  }; 

  char entrein_buffer[1 << 12]; 
  //setvbuf(entrin, entrein_buffer, _IONBF, sizeof(entrein_buffer)); // RL: Unbuffered. 
  setvbuf(entrin, entrein_buffer, _IOLBF, sizeof(entrein_buffer)); // RL: Line buffered. 
  //setvbuf(entrin, entrein_buffer, _IOFBF, sizeof(entrein_buffer)); // RL: Fully buffered. 
  
  nonanime_restart_lexer();
  yynonanimerestart(entrin);
  nonanime_reset_parser();

  /* L'analyse elle meme. */
  int res; 
  yynonanime_global_objet_being_filled_up_while_parsing = this; 
#if 1
  res = yynonanimeparse();
#else
  res = 0;
#endif

  fprintf(yynonanimeout, "\n" "\n"  "---------------------------------------"  "\n" "\n"); 

  
  //* On match. */
  switch (res) {
  case 0:  (void) fprintf(yynonanimeout, "Analyse réussie !!!\n"); break; 
  default: (void) fprintf(yynonanimeout, "Analyse ratée...\n"); break; 
  };

  if (0 == res) { 
    fprintf(yynonanimeout, "\n\n" "==============================================================================" "\n" "\n"); 
    nonanime__print(this, yynonanimeout);   
  }; 
  
  /* On ferme les flux. */
  (void) fclose(yynonanimeout); 
  (void) fclose(yynonanimein);
  
  return (0 == res) ? 0 : -5; 
}; 





