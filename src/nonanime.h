#ifndef NONANIME_H
#define NONANIME_H

enum { nonanime_actions_size = 15 }; 
enum { nonanime_events_size = 15 }; 
enum { nonanime_elements_size = 15 }; 
enum { NONANIME_EVENTS_TOUS, NONANIME_EVENTS_AUCUN, NONANIME_EVENTS_CODE };

struct nonanime_t; 
typedef struct nonanime_t nonanime_t; 



struct nonanime_t {
  char * filename; 
  
  //physique;
  float choc_longueur;
  float choc_largeur;
  float choc_hauteur;
  float masse;
  int compressible;
  int fixe;
  float rebondissement;
  
  //nonanime_tgameplay gameplay;
  int vie;
  int invincible;

  char * actions_array_nom                 [nonanime_actions_size]; 
  int    actions_array_menu                [nonanime_actions_size]; 
  char * actions_array_affichage           [nonanime_actions_size]; 
  char * actions_array_icone               [nonanime_actions_size]; 
  char * actions_array_gestionnaire_fichier[nonanime_actions_size]; 
  char * actions_array_gestionnaire_proc   [nonanime_actions_size]; 
  int    actions_nb; 

  char * events_array_nom                    [nonanime_events_size]; 
  int    events_array_genere_type            [nonanime_events_size]; 
  char * events_array_genere_code_fichier    [nonanime_events_size]; 
  char * events_array_genere_code_proc       [nonanime_events_size]; 
  char * events_array_traitement_code_fichier[nonanime_events_size]; 
  char * events_array_traitement_code_proc   [nonanime_events_size]; 
  int    events_nb; 

  //nonanime_tgraphique graphique;
  char * elements_nom  [nonanime_elements_size]; 
  char * elements_image[nonanime_elements_size]; 
  char * racines       [nonanime_elements_size]; 
  int    elements_nb; 
  
  
  
  // *** TEMPORARY NON-ATTRIBUTE DATA *** 
  const char * temp_code_fichier; 
  const char * temp_code_proc; 
  
  int temp_events_genere_type;
  const char * temp_events_genere_code_fichier;
  const char * temp_events_genere_code_proc; 

  const char * temp_events_par_code_fichier; 
  const char * temp_events_par_code_proc; 
  
  const char * temp_events_traitement_code_fichier; 
  const char * temp_events_traitement_code_proc; 
};

extern nonanime_t * nonanime_make(void);  
extern void nonanime_delete(nonanime_t * this);  

extern nonanime_t * nonanime_make_from_file(const char * filename, const char * log_filename);  

extern int nonanime__fill_from_file(nonanime_t * this, const char * filename, const char * log_filename);  

extern void nonanime__actions_push(nonanime_t * this, const char * actions_nom, const int actions_menu_huh, const char * actions_affichage, const char * actions_icone, const char * actions_gestionnaire_fichier, const char * actions_gestionnaire_proc);  

extern void nonanime__events_push(nonanime_t * this, const char * events_nom, const int events_genere_type, const char * events_genere_code_fichier, const char * events_genere_code_proc, const char * events_traitement_fichier, const char * events_traitement_proc);  

extern void nonanime__elements_push(nonanime_t * this, const char * elements_nom, const char * elements_image); 

extern void nonanime__print(const nonanime_t * this, FILE * out_stream); 



#endif /* NONANIME_H */
