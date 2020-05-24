%{ /* Header */
#include <stdlib.h>
#include <stdio.h>
//#include "global.hpp"
#include "nonanime.global.h"
#include "nonanime.h"
//#include "nonanime.parser.h"
#include "nonanime.parser.tab.h"

static void yyerror(const char * s);
//CObjNonAnime *objet = NULL;

nonanime_t * yynonanime_global_objet_being_filled_up_while_parsing = NULL;
#define this yynonanime_global_objet_being_filled_up_while_parsing



#define VERIF_NOT_NULL(a,b) if (a == NULL) {yyerror("Manque de mémoire."); return b;}



#if 1
void nonanime_reset_parser(void) {
}; 
#else
#define MAXELTBRE 32
static nonanime_eltdesc elttab[MAXELTBRE];
static int eltnbelts = 0;
static int eltlookup(const char * nom) {
  for (int i = 0; i < eltnbelts; i++) {
    if (0 == strcmp(nom, elttab[i].nom)) { return i; }; 
  };
  return -1;
};

void nonanime_reset_parser(void) {
  eltnbelts = 0;
}

#endif 

/*
static void eltempiler(CObjNonAnime *pere, liste *fils) {
  filsdesc *temp;

  while (fils != NULL) {
    int j;
    temp = (filsdesc*) fils->contenu;

    if ((j = eltlookup(temp->qui)) < 0) {
      yyerror(strcat(strcat("Le eltbre \"", temp->qui), " n'a pas ete defini. On continue néanmoins.\n"));
    }
    
    else {
      CPantin *p = new CPantin;
      p->AjouterMembre(memtab[j].image, temp->x, temp->y, temp->z, memtab[j].largeur, memtab[j].hauteur, memtab[j].angle_max_y);
      pere->SetPantinFilsAuDernierMembre(p);
      memempiler(p, memtab[j].fils);
    }
    fils = fils->suivant;
  }
}
*/




%}

/* Le type de yylval. */
/* Attention !!!!!!!!
   Si problème de définition de type, bien regardé le makefile,
   mais surtout avant chaque #include "parser.h"
   avoir mis un #include "le fichier de description des types.h"
*/
%union {
booleen yybooleen;
int yyentier;
double yyreel;
char *yychaine;
char *yyident;
char *yynom;
#if 1
#else 
nonanime_action yylaction;
nonanime_tcode *code;
nonanime_sgenere *genere;
nonanime_filsdesc *yyfilsdesc;
nonanime_tfils *fils;
nonanime_telement *element;
nonanime_tevent *event;
nonanime_taction *yyaction;
liste *yyliste;
nonanime_tnonanime *nonanime;
nonanime_tphysique *physique;
nonanime_tgameplay *gameplay;
nonanime_tgraphique *graphique;
#endif 
}

%token <yybooleen> Token_Booleen
%token <yyentier>  Token_Entier
%token <yyreel>    Token_Reel
%token <yychaine>  Token_Chaine
%token <yyident>   Token_Ident
%token <yyaction>  Token_LAction

%token Token_Assign
//%token Token_Plus Token_Moins
//%token Token_Mult Token_Div

%token Token_OpenPar Token_OpenBrace Token_OpenBracket
%token Token_ClosePar Token_CloseBrace Token_CloseBracket

%token Token_Ptvirg Token_Virgule
%token Token_EOF

%token Token_Zone Token_Choc Token_Masse Token_Invincible
%token Token_Elements Token_Racines
%token Token_Action
%token Token_Menu Token_Affichage Token_Gestionnaire
%token Token_Evenement Token_Genere Token_Par Token_Traitement
%token Token_Element Token_Fils Token_Angle
%token Token_Qui Token_X Token_Y Token_Z
%token Token_Tous Token_Aucun
%token Token_Image

%token Token_Points Token_De Token_Vie

%token Token_Largeur Token_Longueur Token_Hauteur

%token Token_Physique Token_Gameplay Token_Graphique

%token Token_Compressible Token_Fixe Token_Coefficient Token_Rebondissement


%token Token_Fichier Token_Procedure Token_Icone



%type <yyentier> expr_entier expr_entier1 expr_entier2 
%token Token_PlusEntier Token_MoinsEntier Token_MultEntier Token_DivEntier Token_ModEntier

%type <yyreel> expr_reel expr_reel1 expr_reel2
//%token Token_ZSol
%token Token_PlusReel Token_MoinsReel Token_MultReel Token_DivReel





%type <yynom> nom

%type <code> code
%type <genere> genere
%type <yyfilsdesc> fils
%type <element> element
%type <event> evenement 

%type <yyliste> liste_element
%type <yyliste> liste_elements_racines
%type <yyliste> liste_fils
%type <yyliste> liste_evenement

//%type <physique> physique 
//%type <gameplay> gameplay 
//%type <graphique> graphique
//%type <nonanime> main

%start main

%%

main: physique gameplay graphique {
  return 0;
};

physique: 
Token_Physique Token_OpenBrace
 Token_Zone Token_De Token_Choc Token_Assign Token_OpenBrace
  Token_Longueur Token_Assign expr_reel Token_Ptvirg
  Token_Largeur  Token_Assign expr_reel Token_Ptvirg
  Token_Hauteur  Token_Assign expr_reel Token_Ptvirg
 Token_CloseBrace Token_Ptvirg
Token_Masse Token_Assign expr_reel Token_Ptvirg
Token_Compressible Token_Assign Token_Booleen Token_Ptvirg
Token_Fixe Token_Assign Token_Booleen Token_Ptvirg
Token_Coefficient Token_De Token_Rebondissement Token_Assign expr_reel Token_Ptvirg
Token_CloseBrace
{
#if 1
  yynonanime_global_objet_being_filled_up_while_parsing -> choc_longueur = $10; 
  yynonanime_global_objet_being_filled_up_while_parsing -> choc_largeur = $14; 
  yynonanime_global_objet_being_filled_up_while_parsing -> choc_hauteur = $18; 
  yynonanime_global_objet_being_filled_up_while_parsing -> masse = $24; 
  yynonanime_global_objet_being_filled_up_while_parsing -> compressible = $28; 
  yynonanime_global_objet_being_filled_up_while_parsing -> fixe = $32; 
  yynonanime_global_objet_being_filled_up_while_parsing -> rebondissement = $38; 
#else 
  objet -> SetDimension($10, $14, $18);
  /*
  tphysique *temp = new_physique();
  VERIF_NOT_NULL(temp,-2);
  temp->choc = new_vecteur();
  VERIF_NOT_NULL(temp->choc,-3);
  temp->choc->proj.x = $10;
  temp->choc->proj.y = $14;
  temp->choc->proj.z = $18;
  temp->masse = $24;
  temp->compressible = $28;
  temp->fixe = $32;
  temp->rebondissement = $38;
  $$ = temp;
  */
#endif 
};

gameplay:
Token_Gameplay Token_OpenBrace 
 Token_Points Token_De Token_Vie Token_Assign expr_reel     Token_Ptvirg 
 Token_Invincible                Token_Assign Token_Booleen Token_Ptvirg 
 liste_action 
 liste_evenement 
Token_CloseBrace 
{
  /*
  tgameplay *temp = new_gameplay();
  VERIF_NOT_NULL(temp,-4);
  temp->vie = $7;
  temp->invincible = $11;
  
  temp->actions = $13;
  temp->events = $14;
  
  $$ = temp;
  */
};

graphique:
Token_Graphique Token_OpenBrace 
 liste_element
 Token_Elements Token_Racines Token_Assign liste_elements_racines Token_Ptvirg
Token_CloseBrace
{
#if 1
  // Do nothing 
#else
  /*
  filsdesc *temp;
  
  while ($7 != NULL) {
    int j;
    temp = (filsdesc*) $7->contenu;

    if ((j = eltlookup(temp->qui)) < 0) {
      yyerror(strcat(strcat("Le membre \"", temp->qui), "\" n'a pas ete defini. On continue néanmoins.\n"));
    }
    
    else {
      bongars->AjouterMembre(memtab[j].image, temp->x, temp->y, temp->z, memtab[j].largeur, memtab[j].hauteur, memtab[j].angle_max_y);
      memempiler(bongars, memtab[j].fils);
    }
    $7 = $7->suivant;
  }
  */


 if ($7 == NULL) {
    objet->resobj3ds = NULL;
  }

 else {
   int indice = eltlookup(((nonanime_filsdesc *) ($7->contenu))->qui);
   if (indice < 0) {
     objet->resobj3ds = NULL;
   }
   
   else {
     objet->resobj3ds = gestion3DS.prendre(elttab[indice].image);
   }
 }
 
 /*
   
   tgraphique *temp = new_graphique();
   VERIF_NOT_NULL(temp,-5);
   $$->racines = $7;
   $$ = temp;
 */
#endif 
};


liste_action:
liste_action action
| 
;

action:
Token_Action nom Token_OpenBrace
  Token_Affichage    Token_Assign Token_Chaine Token_Ptvirg 
  Token_Icone        Token_Assign Token_Chaine Token_Ptvirg 
  Token_Gestionnaire Token_Assign code         Token_Ptvirg 
Token_CloseBrace 
{
#if 1
  nonanime__actions_push(yynonanime_global_objet_being_filled_up_while_parsing, $2, faux, /*actions_affichage*/$6, /*actions_icone*/$10, /*actions_gestionnaire_fichier*/yynonanime_global_objet_being_filled_up_while_parsing -> temp_code_fichier, /*actions_gestionnaire_proc*/yynonanime_global_objet_being_filled_up_while_parsing -> temp_code_proc);  
#else 
  objet->AjouterAction($6, $10, $14->fichier, $14->proc);
  nonanime_del_code(&($14));
#endif 
};

liste_evenement:
  liste_evenement evenement {
#if 0
    $$ = mp($2, $1); 
    VERIF_NOT_NULL($$,-8); 
#endif 
  }
| {
#if 0
    $$ = liste_vide();
#endif 
}
;

evenement:
Token_Evenement nom Token_OpenBrace
  Token_Genere Token_Par Token_Assign genere Token_Ptvirg
  Token_Traitement       Token_Assign code   Token_Ptvirg
Token_CloseBrace
{
#if 1
  nonanime__events_push(yynonanime_global_objet_being_filled_up_while_parsing, /*events_nom*/$2, 
    /*events_genere_type*/yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_type, /*events_genere_code_fichier*/yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_code_fichier, /*events_genere_code_proc*/yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_code_proc, 
    /*events_traitement_fichier*/yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_traitement_code_fichier, /*events_traitement_proc*/yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_traitement_code_proc);  

#else
  $$ = nonanime_new_event();
  VERIF_NOT_NULL($$,-9)

  $$->genere = $7->type;
  if ($7->type == CODE) {
    $$->par = NULL;
  }

  else {
    $$->par = $7->code;
  }

  nonanime_del_sgenere(&($7));
  $$->traitement = $11;
#endif 
};

liste_element:
  liste_element element {
#if 0
    $$ = mp($2, $1); VERIF_NOT_NULL($$,-10);
#endif
}
| {
#if 0
$$ = liste_vide();
#endif 
}
;

element:
 Token_Element nom Token_OpenBrace
 Token_Fils  Token_Assign liste_fils   Token_Ptvirg
 Token_Image Token_Assign Token_Chaine Token_Ptvirg
Token_CloseBrace
{
#if 1
  nonanime__elements_push(yynonanime_global_objet_being_filled_up_while_parsing, $2, $10); 
#else
 if (eltnbelts < MAXELTBRE) {
    elttab[eltnbelts].nom = $2;
    elttab[eltnbelts].image = $10;
    elttab[eltnbelts].fils = $6;
    eltnbelts++;
  }
 $$ = NULL;
#endif
};

liste_elements_racines: liste_fils {
#if 0
$$ = $1;
#endif 
};

liste_fils:
  liste_fils fils liste_virg {
#if 0
$$ = mp($2, $1); VERIF_NOT_NULL($$,-12);
#endif 
}
| liste_virg {
#if 0
$$ = liste_vide();
#endif 
}
;

fils:
Token_OpenBrace
 Token_Qui Token_Assign Token_Ident Token_Ptvirg
 Token_X Token_Assign expr_reel Token_Ptvirg
 Token_Y Token_Assign expr_reel Token_Ptvirg
 Token_Z Token_Assign expr_reel Token_Ptvirg
 Token_Angle Token_X Token_Assign expr_reel Token_Ptvirg
 Token_Angle Token_Y Token_Assign expr_reel Token_Ptvirg
 Token_Angle Token_Z Token_Assign expr_reel Token_Ptvirg
Token_CloseBrace
{
#if 1
  //$$ = NULL; 
#else
  $$ = new nonanime_filsdesc;
  $$->qui = $4;
  $$->x = $8;
  $$->y = $12;
  $$->z = $16;
  $$->angle_x = $21;
  $$->angle_y = $26;
  $$->angle_z = $31;
  /*
  $$ = new_fils();
  VERIF_NOT_NULL($$,-13);
  $$->qui = (telement*) $4; // lookup en realite
  $$->x = $8;
  $$->y = $12;
  $$->z = $16;
  $$->angle_x = $21;
  $$->angle_y = $26;
  $$->angle_z = $31;
  */
#endif
};


liste_virg:
  liste_virg Token_Virgule
| 
  ;


genere:
  Token_Aucun {
#if 1 
    yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_type         = NONANIME_EVENTS_AUCUN; 
    yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_code_fichier = NULL; 
    yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_code_proc    = NULL; 
#else
$$ = nonanime_new_sgenere(); VERIF_NOT_NULL($$,-14); $$->type = AUCUN; $$->code =NULL;
#endif 
}
| Token_Tous {
#if 1 
  yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_type         = NONANIME_EVENTS_TOUS; 
  yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_code_fichier = NULL; 
  yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_code_proc    = NULL; 
#else
  $$ = nonanime_new_sgenere(); VERIF_NOT_NULL($$,-15); $$->type = TOUS; $$->code = NULL;
#endif
}
| code {
#if 1
  yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_type         = NONANIME_EVENTS_CODE; 
  yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_code_fichier = yynonanime_global_objet_being_filled_up_while_parsing -> temp_code_fichier; 
  yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_code_proc    = yynonanime_global_objet_being_filled_up_while_parsing -> temp_code_fichier; 
#else 
  $$ = nonanime_new_sgenere(); VERIF_NOT_NULL($$,-16); $$->type = CODE; $$->code = $1;
#endif
}
;

code:
Token_OpenBrace 
Token_Fichier   Token_Assign Token_Chaine Token_Ptvirg 
Token_Procedure Token_Assign Token_Chaine Token_Ptvirg
Token_CloseBrace
{ 
#if 1
  yynonanime_global_objet_being_filled_up_while_parsing -> temp_code_fichier = $4;
  yynonanime_global_objet_being_filled_up_while_parsing -> temp_code_proc = $8; 
#else
  $$ = nonanime_new_code(); $$->fichier = $4; $$->proc = $8; 
#endif
};







expr_entier:
expr_entier Token_PlusEntier expr_entier1 { $$ = $1 + $3; }
| expr_entier Token_MoinsEntier expr_entier1 { $$ = $1 - $3; }
| expr_entier1 { $$= $1; }
;

expr_entier1:
expr_entier1 Token_MultEntier expr_entier2 { $$ = $1 * $3; }
| expr_entier1 Token_DivEntier expr_entier2 { $$ = $1 / $3; }
| expr_entier1 Token_ModEntier expr_entier2 { $$ = $1 % $3; }
| expr_entier2 { $$ = $1; }
;

expr_entier2:
Token_Entier { $$ = $1; }
| Token_PlusEntier expr_entier2 { $$ = $2; }
| Token_MoinsEntier expr_entier2 { $$ = - $2; }
| Token_OpenPar expr_entier Token_ClosePar { $$ = $2; }
;


expr_reel:
  expr_reel Token_PlusReel    expr_reel1 { $$ = $1 + $3; }
| expr_reel Token_PlusEntier  expr_reel1 { $$ = $1 + $3; }
| expr_reel Token_MoinsReel   expr_reel1 { $$ = $1 - $3; }
| expr_reel Token_MoinsEntier expr_reel1 { $$ = $1 - $3; }
| expr_reel1 { $$= $1; }
;

expr_reel1:
  expr_reel1 Token_MultReel   expr_reel2 { $$ = $1 * $3; }
| expr_reel1 Token_MultEntier expr_reel2 { $$ = $1 * $3; }
| expr_reel1 Token_DivReel    expr_reel2 { $$ = $1 / $3; }
| expr_reel1 Token_DivEntier  expr_reel2 { $$ = $1 / $3; }
| expr_reel2 { $$ = $1; }
;

expr_reel2:
  Token_Reel { $$ = $1; }
| Token_Entier { $$ = $1; }
| Token_PlusReel    expr_reel2 { $$ = $2; }
| Token_PlusEntier  expr_reel2 { $$ = $2; }
| Token_MoinsReel   expr_reel2 { $$ = - $2; }
| Token_MoinsEntier expr_reel2 { $$ = - $2; }
| Token_OpenPar expr_reel Token_ClosePar { $$ = $2; }
;


nom:
  Token_Chaine { $$ = $1; }
| Token_Ident  { $$ = $1; }
;






%%

/*extern void yyerror(char *msg);*/
#include <stdio.h>
static void yyerror(const char * s) {
  const int a = nonanime_get_nb_chars();
  const int b = nonanime_get_nb_chars_tot();
  const int c = nonanime_get_yyleng();
  //(void) fprintf(stderr, "%s: Erreur d'analyse syntaxique sur le lexème \"%s\" à la ligne %d (caractères %d (%d) à %d (%d)) [%s]\n", this -> filename, nonanime_get_yytext(), nonanime_get_nb_lignes() + 1, a - c, b - c, a - 1, b - 1, s);
  nonanime_err("%s:%d:%d-%d: Erreur d'analyse syntaxique sur le lexème \"%s\" [%s]\n", this -> filename, nonanime_get_nb_lignes() + 1, a - c, a - 1, nonanime_get_yytext(), s);
}; 

