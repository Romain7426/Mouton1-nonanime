#include <stdlib.h>
#include <string.h>
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYLEX yylex()
#define YYEMPTY -1
#define yyclearin (yychar=(YYEMPTY))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING() (yyerrflag!=0)
#define yyparse yynonanimeparse
#define yylex yynonanimelex
#define yyerror yynonanimeerror
#define yychar yynonanimechar
#define yyval yynonanimeval
#define yylval yynonanimelval
#define yydebug yynonanimedebug
#define yynerrs yynonanimenerrs
#define yyerrflag yynonanimeerrflag
#define yyss yynonanimess
#define yysslim yynonanimesslim
#define yyssp yynonanimessp
#define yyvs yynonanimevs
#define yyvsp yynonanimevsp
#define yystacksize yynonanimestacksize
#define yylhs yynonanimelhs
#define yylen yynonanimelen
#define yydefred yynonanimedefred
#define yydgoto yynonanimedgoto
#define yysindex yynonanimesindex
#define yyrindex yynonanimerindex
#define yygindex yynonanimegindex
#define yytable yynonanimetable
#define yycheck yynonanimecheck
#define yyname yynonanimename
#define yyrule yynonanimerule
#define YYPREFIX "yynonanime"
#line 1 "src/nonanime.parser.y"
 /* Header */
#include <stdlib.h>
#include <stdio.h>
/*#include "global.hpp"*/
#include "nonanime.global.h"
#include "nonanime.h"
/*#include "nonanime.parser.h"*/
#include "nonanime.parser.tab.h"

static void yyerror(const char * s);
/*CObjNonAnime *objet = NULL;*/

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




#line 76 "src/nonanime.parser.y"
#ifndef YYSTYPE_DEFINED
#define YYSTYPE_DEFINED
typedef union {
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
} YYSTYPE;
#endif /* YYSTYPE_DEFINED */
#line 135 "src/nonanime.parser.code.c"
#define Token_Booleen 257
#define Token_Entier 258
#define Token_Reel 259
#define Token_Chaine 260
#define Token_Ident 261
#define Token_LAction 262
#define Token_Assign 263
#define Token_OpenPar 264
#define Token_OpenBrace 265
#define Token_OpenBracket 266
#define Token_ClosePar 267
#define Token_CloseBrace 268
#define Token_CloseBracket 269
#define Token_Ptvirg 270
#define Token_Virgule 271
#define Token_EOF 272
#define Token_Zone 273
#define Token_Choc 274
#define Token_Masse 275
#define Token_Invincible 276
#define Token_Elements 277
#define Token_Racines 278
#define Token_Action 279
#define Token_Menu 280
#define Token_Affichage 281
#define Token_Gestionnaire 282
#define Token_Evenement 283
#define Token_Genere 284
#define Token_Par 285
#define Token_Traitement 286
#define Token_Element 287
#define Token_Fils 288
#define Token_Angle 289
#define Token_Qui 290
#define Token_X 291
#define Token_Y 292
#define Token_Z 293
#define Token_Tous 294
#define Token_Aucun 295
#define Token_Image 296
#define Token_Points 297
#define Token_De 298
#define Token_Vie 299
#define Token_Largeur 300
#define Token_Longueur 301
#define Token_Hauteur 302
#define Token_Physique 303
#define Token_Gameplay 304
#define Token_Graphique 305
#define Token_Compressible 306
#define Token_Fixe 307
#define Token_Coefficient 308
#define Token_Rebondissement 309
#define Token_Fichier 310
#define Token_Procedure 311
#define Token_Icone 312
#define Token_PlusEntier 313
#define Token_MoinsEntier 314
#define Token_MultEntier 315
#define Token_DivEntier 316
#define Token_ModEntier 317
#define Token_PlusReel 318
#define Token_MoinsReel 319
#define Token_MultReel 320
#define Token_DivReel 321
#define YYERRCODE 256
#define YYTABLESIZE 274
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 321
extern const short yylhs[];
extern const short yylen[];
extern const short yydefred[];
extern const short yydgoto[];
extern const short yysindex[];
extern const short yyrindex[];
extern const short yygindex[];
extern const short yytable[];
extern const short yycheck[];
#if YYDEBUG
extern const char *const yyname[];
extern const char *const yyrule[];
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH 10000
#endif
#endif
#define YYINITSTACKSIZE 200
/* LINTUSED */
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short *yyss;
short *yysslim;
YYSTYPE *yyvs;
unsigned int yystacksize;
int yyparse(void);
#line 559 "src/nonanime.parser.y"


/*extern void yyerror(char *msg);*/
#include <stdio.h>
static void yyerror(const char * s) {
  const int a = nonanime_get_nb_chars();
  const int b = nonanime_get_nb_chars_tot();
  const int c = nonanime_get_yyleng();
  //(void) fprintf(stderr, "%s: Erreur d'analyse syntaxique sur le lexème \"%s\" à la ligne %d (caractères %d (%d) à %d (%d)) [%s]\n", this -> filename, nonanime_get_yytext(), nonanime_get_nb_lignes() + 1, a - c, b - c, a - 1, b - 1, s);
  nonanime_err("%s:%d:%d-%d: Erreur d'analyse syntaxique sur le lexème \"%s\" [%s]\n", this -> filename, nonanime_get_nb_lignes() + 1, a - c, a - 1, nonanime_get_yytext(), s);
}; 

#line 260 "src/nonanime.parser.code.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    unsigned int newsize;
    long sslen;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;
    sslen = yyssp - yyss;
#ifdef SIZE_MAX
#define YY_SIZE_MAX SIZE_MAX
#else
#define YY_SIZE_MAX 0xffffffffU
#endif
    if (newsize && YY_SIZE_MAX / newsize < sizeof *newss)
        goto bail;
    newss = yyss ? (short *)realloc(yyss, newsize * sizeof *newss) :
      (short *)malloc(newsize * sizeof *newss); /* overflow check above */
    if (newss == NULL)
        goto bail;
    yyss = newss;
    yyssp = newss + sslen;
    if (newsize && YY_SIZE_MAX / newsize < sizeof *newvs)
        goto bail;
    newvs = yyvs ? (YYSTYPE *)realloc(yyvs, newsize * sizeof *newvs) :
      (YYSTYPE *)malloc(newsize * sizeof *newvs); /* overflow check above */
    if (newvs == NULL)
        goto bail;
    yyvs = newvs;
    yyvsp = newvs + sslen;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
bail:
    if (yyss)
            free(yyss);
    if (yyvs)
            free(yyvs);
    yyss = yyssp = NULL;
    yyvs = yyvsp = NULL;
    yystacksize = 0;
    return -1;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif /* YYDEBUG */

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#if defined(__GNUC__)
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#if defined(__GNUC__)
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 174 "src/nonanime.parser.y"
{
  return 0;
}
break;
case 2:
#line 190 "src/nonanime.parser.y"
{
#if 1
  yynonanime_global_objet_being_filled_up_while_parsing -> choc_longueur = yyvsp[-30].yyreel; 
  yynonanime_global_objet_being_filled_up_while_parsing -> choc_largeur = yyvsp[-26].yyreel; 
  yynonanime_global_objet_being_filled_up_while_parsing -> choc_hauteur = yyvsp[-22].yyreel; 
  yynonanime_global_objet_being_filled_up_while_parsing -> masse = yyvsp[-16].yyreel; 
  yynonanime_global_objet_being_filled_up_while_parsing -> compressible = yyvsp[-12].yybooleen; 
  yynonanime_global_objet_being_filled_up_while_parsing -> fixe = yyvsp[-8].yybooleen; 
  yynonanime_global_objet_being_filled_up_while_parsing -> rebondissement = yyvsp[-2].yyreel; 
#else 
  objet -> SetDimension(yyvsp[-30].yyreel, yyvsp[-26].yyreel, yyvsp[-22].yyreel);
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
}
break;
case 3:
#line 225 "src/nonanime.parser.y"
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
}
break;
case 4:
#line 244 "src/nonanime.parser.y"
{
#if 1
  /* Do nothing */
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


 if (yyvsp[-2].yyliste == NULL) {
    objet->resobj3ds = NULL;
  }

 else {
   int indice = eltlookup(((nonanime_filsdesc *) (yyvsp[-2].yyliste->contenu))->qui);
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
}
break;
case 7:
#line 305 "src/nonanime.parser.y"
{
#if 1
  nonanime__actions_push(yynonanime_global_objet_being_filled_up_while_parsing, yyvsp[-14].yynom, faux, /*actions_affichage*/yyvsp[-10].yychaine, /*actions_icone*/yyvsp[-6].yychaine, /*actions_gestionnaire_fichier*/yynonanime_global_objet_being_filled_up_while_parsing -> temp_code_fichier, /*actions_gestionnaire_proc*/yynonanime_global_objet_being_filled_up_while_parsing -> temp_code_proc);  
#else 
  objet->AjouterAction(yyvsp[-10].yychaine, yyvsp[-6].yychaine, yyvsp[-2].code->fichier, yyvsp[-2].code->proc);
  nonanime_del_code(&(yyvsp[-2].code));
#endif 
}
break;
case 8:
#line 315 "src/nonanime.parser.y"
{
#if 0
    yyval.yyliste = mp(yyvsp[0].event, yyvsp[-1].yyliste); 
    VERIF_NOT_NULL(yyval.yyliste,-8); 
#endif 
  }
break;
case 9:
#line 321 "src/nonanime.parser.y"
{
#if 0
    yyval.yyliste = liste_vide();
#endif 
}
break;
case 10:
#line 333 "src/nonanime.parser.y"
{
#if 1
  nonanime__events_push(yynonanime_global_objet_being_filled_up_while_parsing, /*events_nom*/yyvsp[-11].yynom, 
    /*events_genere_type*/yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_type, /*events_genere_code_fichier*/yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_code_fichier, /*events_genere_code_proc*/yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_code_proc, 
    /*events_traitement_fichier*/yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_traitement_code_fichier, /*events_traitement_proc*/yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_traitement_code_proc);  

#else
  yyval.event = nonanime_new_event();
  VERIF_NOT_NULL(yyval.event,-9)

  yyval.event->genere = yyvsp[-6].genere->type;
  if (yyvsp[-6].genere->type == CODE) {
    yyval.event->par = NULL;
  }

  else {
    yyval.event->par = yyvsp[-6].genere->code;
  }

  nonanime_del_sgenere(&(yyvsp[-6].genere));
  yyval.event->traitement = yyvsp[-2].code;
#endif 
}
break;
case 11:
#line 358 "src/nonanime.parser.y"
{
#if 0
    yyval.yyliste = mp(yyvsp[0].element, yyvsp[-1].yyliste); VERIF_NOT_NULL(yyval.yyliste,-10);
#endif
}
break;
case 12:
#line 363 "src/nonanime.parser.y"
{
#if 0
yyval.yyliste = liste_vide();
#endif 
}
break;
case 13:
#line 375 "src/nonanime.parser.y"
{
#if 1
  nonanime__elements_push(yynonanime_global_objet_being_filled_up_while_parsing, yyvsp[-10].yynom, yyvsp[-2].yychaine); 
#else
 if (eltnbelts < MAXELTBRE) {
    elttab[eltnbelts].nom = yyvsp[-10].yynom;
    elttab[eltnbelts].image = yyvsp[-2].yychaine;
    elttab[eltnbelts].fils = yyvsp[-6].yyliste;
    eltnbelts++;
  }
 yyval.element = NULL;
#endif
}
break;
case 14:
#line 389 "src/nonanime.parser.y"
{
#if 0
yyval.yyliste = yyvsp[0].yyliste;
#endif 
}
break;
case 15:
#line 396 "src/nonanime.parser.y"
{
#if 0
yyval.yyliste = mp(yyvsp[-1].yyfilsdesc, yyvsp[-2].yyliste); VERIF_NOT_NULL(yyval.yyliste,-12);
#endif 
}
break;
case 16:
#line 401 "src/nonanime.parser.y"
{
#if 0
yyval.yyliste = liste_vide();
#endif 
}
break;
case 17:
#line 418 "src/nonanime.parser.y"
{
#if 1
  /*$$ = NULL; */
#else
  yyval.yyfilsdesc = new nonanime_filsdesc;
  yyval.yyfilsdesc->qui = yyvsp[-29].yyident;
  yyval.yyfilsdesc->x = yyvsp[-25].yyreel;
  yyval.yyfilsdesc->y = yyvsp[-21].yyreel;
  yyval.yyfilsdesc->z = yyvsp[-17].yyreel;
  yyval.yyfilsdesc->angle_x = yyvsp[-12].yyreel;
  yyval.yyfilsdesc->angle_y = yyvsp[-7].yyreel;
  yyval.yyfilsdesc->angle_z = yyvsp[-2].yyreel;
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
}
break;
case 20:
#line 452 "src/nonanime.parser.y"
{
#if 1 
    yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_type         = NONANIME_EVENTS_AUCUN; 
    yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_code_fichier = NULL; 
    yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_code_proc    = NULL; 
#else
yyval.genere = nonanime_new_sgenere(); VERIF_NOT_NULL(yyval.genere,-14); yyval.genere->type = AUCUN; yyval.genere->code =NULL;
#endif 
}
break;
case 21:
#line 461 "src/nonanime.parser.y"
{
#if 1 
  yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_type         = NONANIME_EVENTS_TOUS; 
  yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_code_fichier = NULL; 
  yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_code_proc    = NULL; 
#else
  yyval.genere = nonanime_new_sgenere(); VERIF_NOT_NULL(yyval.genere,-15); yyval.genere->type = TOUS; yyval.genere->code = NULL;
#endif
}
break;
case 22:
#line 470 "src/nonanime.parser.y"
{
#if 1
  yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_type         = NONANIME_EVENTS_CODE; 
  yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_code_fichier = yynonanime_global_objet_being_filled_up_while_parsing -> temp_code_fichier; 
  yynonanime_global_objet_being_filled_up_while_parsing -> temp_events_genere_code_proc    = yynonanime_global_objet_being_filled_up_while_parsing -> temp_code_fichier; 
#else 
  yyval.genere = nonanime_new_sgenere(); VERIF_NOT_NULL(yyval.genere,-16); yyval.genere->type = CODE; yyval.genere->code = yyvsp[0].code;
#endif
}
break;
case 23:
#line 486 "src/nonanime.parser.y"
{ 
#if 1
  yynonanime_global_objet_being_filled_up_while_parsing -> temp_code_fichier = yyvsp[-6].yychaine;
  yynonanime_global_objet_being_filled_up_while_parsing -> temp_code_proc = yyvsp[-2].yychaine; 
#else
  yyval.code = nonanime_new_code(); yyval.code->fichier = yyvsp[-6].yychaine; yyval.code->proc = yyvsp[-2].yychaine; 
#endif
}
break;
case 24:
#line 502 "src/nonanime.parser.y"
{ yyval.yyentier = yyvsp[-2].yyentier + yyvsp[0].yyentier; }
break;
case 25:
#line 503 "src/nonanime.parser.y"
{ yyval.yyentier = yyvsp[-2].yyentier - yyvsp[0].yyentier; }
break;
case 26:
#line 504 "src/nonanime.parser.y"
{ yyval.yyentier= yyvsp[0].yyentier; }
break;
case 27:
#line 508 "src/nonanime.parser.y"
{ yyval.yyentier = yyvsp[-2].yyentier * yyvsp[0].yyentier; }
break;
case 28:
#line 509 "src/nonanime.parser.y"
{ yyval.yyentier = yyvsp[-2].yyentier / yyvsp[0].yyentier; }
break;
case 29:
#line 510 "src/nonanime.parser.y"
{ yyval.yyentier = yyvsp[-2].yyentier % yyvsp[0].yyentier; }
break;
case 30:
#line 511 "src/nonanime.parser.y"
{ yyval.yyentier = yyvsp[0].yyentier; }
break;
case 31:
#line 515 "src/nonanime.parser.y"
{ yyval.yyentier = yyvsp[0].yyentier; }
break;
case 32:
#line 516 "src/nonanime.parser.y"
{ yyval.yyentier = yyvsp[0].yyentier; }
break;
case 33:
#line 517 "src/nonanime.parser.y"
{ yyval.yyentier = - yyvsp[0].yyentier; }
break;
case 34:
#line 518 "src/nonanime.parser.y"
{ yyval.yyentier = yyvsp[-1].yyentier; }
break;
case 35:
#line 523 "src/nonanime.parser.y"
{ yyval.yyreel = yyvsp[-2].yyreel + yyvsp[0].yyreel; }
break;
case 36:
#line 524 "src/nonanime.parser.y"
{ yyval.yyreel = yyvsp[-2].yyreel + yyvsp[0].yyreel; }
break;
case 37:
#line 525 "src/nonanime.parser.y"
{ yyval.yyreel = yyvsp[-2].yyreel - yyvsp[0].yyreel; }
break;
case 38:
#line 526 "src/nonanime.parser.y"
{ yyval.yyreel = yyvsp[-2].yyreel - yyvsp[0].yyreel; }
break;
case 39:
#line 527 "src/nonanime.parser.y"
{ yyval.yyreel= yyvsp[0].yyreel; }
break;
case 40:
#line 531 "src/nonanime.parser.y"
{ yyval.yyreel = yyvsp[-2].yyreel * yyvsp[0].yyreel; }
break;
case 41:
#line 532 "src/nonanime.parser.y"
{ yyval.yyreel = yyvsp[-2].yyreel * yyvsp[0].yyreel; }
break;
case 42:
#line 533 "src/nonanime.parser.y"
{ yyval.yyreel = yyvsp[-2].yyreel / yyvsp[0].yyreel; }
break;
case 43:
#line 534 "src/nonanime.parser.y"
{ yyval.yyreel = yyvsp[-2].yyreel / yyvsp[0].yyreel; }
break;
case 44:
#line 535 "src/nonanime.parser.y"
{ yyval.yyreel = yyvsp[0].yyreel; }
break;
case 45:
#line 539 "src/nonanime.parser.y"
{ yyval.yyreel = yyvsp[0].yyreel; }
break;
case 46:
#line 540 "src/nonanime.parser.y"
{ yyval.yyreel = yyvsp[0].yyentier; }
break;
case 47:
#line 541 "src/nonanime.parser.y"
{ yyval.yyreel = yyvsp[0].yyreel; }
break;
case 48:
#line 542 "src/nonanime.parser.y"
{ yyval.yyreel = yyvsp[0].yyreel; }
break;
case 49:
#line 543 "src/nonanime.parser.y"
{ yyval.yyreel = - yyvsp[0].yyreel; }
break;
case 50:
#line 544 "src/nonanime.parser.y"
{ yyval.yyreel = - yyvsp[0].yyreel; }
break;
case 51:
#line 545 "src/nonanime.parser.y"
{ yyval.yyreel = yyvsp[-1].yyreel; }
break;
case 52:
#line 550 "src/nonanime.parser.y"
{ yyval.yynom = yyvsp[0].yychaine; }
break;
case 53:
#line 551 "src/nonanime.parser.y"
{ yyval.yynom = yyvsp[0].yyident; }
break;
#line 862 "src/nonanime.parser.code.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    if (yyss)
            free(yyss);
    if (yyvs)
            free(yyvs);
    yyss = yyssp = NULL;
    yyvs = yyvsp = NULL;
    yystacksize = 0;
    return (1);
yyaccept:
    if (yyss)
            free(yyss);
    if (yyvs)
            free(yyvs);
    yyss = yyssp = NULL;
    yyvs = yyvsp = NULL;
    yystacksize = 0;
    return (0);
}
