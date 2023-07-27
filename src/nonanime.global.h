#ifndef NONANIME_GLOBAL_H
#define NONANIME_GLOBAL_H

//#include "../global.hpp"
//#include "objnonanime.hpp"
#include "nonanime.h"

extern  int nonanime_get_nb_lignes(void);
extern  int nonanime_get_nb_chars(void);
extern  int nonanime_get_nb_chars_tot(void);
extern  int nonanime_get_yyleng(void);
extern  char * nonanime_get_yytext(void);
extern int yynonanimelex(void);
extern void yynonanimerestart(FILE * new_file);
extern  void nonanime_restart_lexer(void);

//extern int eltnbelts;
extern void nonanime_reset_parser(void);

enum booleen {faux = (0 != 0), vrai = (0 == 0)};
typedef enum booleen booleen;


typedef float corps;
/*
const static float pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068;
const static float e = 2.718281828459045235360287471352662497757247093699959574966967627724076630353547594571382178525166427;
*/

#define pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068 
#define e 2.718281828459045235360287471352662497757247093699959574966967627724076630353547594571382178525166427 


// RL: We can't declare it 'extern' otherwise it will be in the library and it will collide with libraries which provide the same function... 
// RL: However, if for any reason, no external library provide such a function, we then have to provide it. 
//extern char * strcopy(const char * str); 
extern char * nonanime_strcopy(const char * str); 
#ifndef strcopy 
#define strcopy nonanime_strcopy 
#endif 


extern FILE * yynonanimein;
extern FILE * yynonanimeout;
#define stderr_FILE stderr

#define BIGLIB_STRING(s) BIGLIB_STRINGX(s)
#define BIGLIB_STRINGX(s) #s

#define nonanime_mess(...)						\
  fprintf(yynonanimeout == NULL ? stderr_FILE : yynonanimeout, "NONANIME_DESCRIPTION: " __FILE__ ": " BIGLIB_STRING(__LINE__) ": " BIGLIB_STRING(__func__) ": "  __VA_ARGS__); 
//putc('\n', yynonanimeout); 
//#define nonanime_err(format_mess,...)  fprintf(yynonanimeout, "ERREUR: " "NONANIME_DESCRIPTION: " __FILE__ ": " BIGLIB_STRING(__LINE__) ": " __FUNC__ ": " format_mess "\n", __VA_ARGS__);
#define nonanime_err(...)	{					\
    if (NULL != yynonanimeout) { fprintf(yynonanimeout, "ERREUR: " "NONANIME_DESCRIPTION: " __FILE__ ": " BIGLIB_STRING(__LINE__) ": " BIGLIB_STRING(__func__) ": " __VA_ARGS__); }; \
    fprintf(                    stderr_FILE  ,            "NONANIME_DESCRIPTION: " __FILE__ ": " BIGLIB_STRING(__LINE__) ": " BIGLIB_STRING(__func__) ": " __VA_ARGS__); \
  };
  //putc('\n', yynonanimeout); 

#define message nonanime_mess

#define MALLOC_BZERO(ctype_t,this) ctype_t * this = NULL; this = (ctype_t *) malloc(sizeof(*this)); bzero(this, sizeof(*this)); 


extern nonanime_t * yynonanime_global_objet_being_filled_up_while_parsing;


#if 0 
/* La structure de liste. */
struct liste {
  void * contenu;
  struct liste * suivant;
};
typedef struct liste liste; 

extern liste * liste_vide(void);
extern liste * mp(void *, liste *);
extern  void raz(liste **);



struct nonanime_filsdesc {
char * qui;
corps x, y, z;
corps angle_x, angle_y, angle_z;
};
typedef struct nonanime_filsdesc nonanime_filsdesc; 

struct nonanime_eltdesc {
char * nom;
char * image;
liste * fils;
};
typedef struct nonanime_eltdesc nonanime_eltdesc;





enum nonanime_action {parler, voler};
typedef enum nonanime_action nonanime_action;
static const int nonanime_nb_actions = 2;


/* Maintenant, on va mettre une sémantique au programme.
   Pour cela on déclare les structures objets. */

#if 0
/* Un point ou un vecteur, c'est la même chose. */
union tvecteur {
  corps coord[3];
  struct {corps x, y, z;} proj;
};

extern tvecteur* new_vecteur(void);
//const extern void del_vecteur(tvecteur **);
extern  void del_vecteur(tvecteur *);
#endif 


/* La partie physique. */
struct nonanime_tphysique {
  float choc[3];
  corps masse;
  booleen compressible;
  booleen fixe;
  corps rebondissement;
};
typedef struct nonanime_tphysique nonanime_tphysique; 
extern nonanime_tphysique* nonanime_new_physique(void);
extern  void nonanime_del_physique(nonanime_tphysique* *);

/* Problème de la définition du code. */
//typedef int *nonanime_tcode;
struct nonanime_tcode {
  char * fichier;
  char * proc;
};
typedef struct nonanime_tcode nonanime_tcode; 
extern nonanime_tcode *nonanime_new_code(void);
extern void nonanime_del_code(nonanime_tcode **);



/* Maintenant on définit les actions. */
struct nonanime_taction {
  booleen menu;
  char * affichage;
  nonanime_tcode *gestionnaire;
};
typedef struct nonanime_taction nonanime_taction; 
extern nonanime_taction * nonanime_new_action(void);
extern  void nonanime_del_action(nonanime_taction * *);


/* Maintenant, la gestion du 'genere par' d'un évènement. */
enum nonanime_tgenere {TOUS, AUCUN, CODE};
typedef enum nonanime_tgenere nonanime_tgenere;
struct nonanime_sgenere {
  nonanime_tgenere type;
  nonanime_tcode * code;
};
typedef struct nonanime_sgenere nonanime_sgenere;
extern nonanime_sgenere* nonanime_new_sgenere(void);
extern  void nonanime_del_sgenere(nonanime_sgenere * *);

/* On peut passer à la définition des évènements. */
struct nonanime_tevent {
  nonanime_tgenere genere;
  nonanime_tcode * par;
  nonanime_tcode * traitement;
};
typedef struct nonanime_tevent nonanime_tevent; 
extern nonanime_tevent * nonanime_new_event(void);
extern  void nonanime_del_event(nonanime_tevent * *);


/* La partie gameplay. */
struct nonanime_tgameplay {
  unsigned int vie;
  booleen invinsible;
  liste actions;
  liste events;
};
typedef struct nonanime_tgameplay nonanime_tgameplay;
extern nonanime_tgameplay * nonanime_new_gameplay(void);
extern  void nonanime_del_gameplay(nonanime_tgameplay * *);



struct nonanime_telement {
  liste fils;
  char * image;
};
typedef struct nonanime_telement nonanime_telement; 
extern nonanime_telement* nonanime_new_element(void);
extern  void nonanime_del_element(nonanime_telement * *);


struct nonanime_tfils {
  struct nonanime_telement *qui;
  corps x, y, z;
  corps angle_x, angle_y, angle_z;
};
typedef struct nonanime_tfils nonanime_tfils;
extern nonanime_tfils* nonanime_new_fils(void);
extern  void nonanime_del_fils(nonanime_tfils * *);

/* La partie graphique. */
struct nonanime_tgraphique {
  liste racines;
};
typedef struct nonanime_tgraphique nonanime_tgraphique;   
extern nonanime_tgraphique* nonanime_new_graphique(void);
extern  void nonanime_del_graphique(nonanime_tgraphique * *);


/* Et enfin, l'aboutissement. */
struct nonanime_tnonanime {
  nonanime_tphysique physique;
  nonanime_tgameplay gameplay;
  nonanime_tgraphique graphique;
};
typedef struct nonanime_tnonanime nonanime_tnonanime; 
extern nonanime_tnonanime* nonanime_new_nonanime(void);
extern  void nonanime_del_nonanime(nonanime_tnonanime * *);

#endif 


#endif /* NONANIME_GLOBAL_H */
