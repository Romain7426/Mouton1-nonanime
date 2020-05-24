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
extern YYSTYPE yynonanimelval;
