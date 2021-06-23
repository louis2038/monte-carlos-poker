#include <stdlib.h>
#include <stdio.h>
#include <time.h>




typedef enum CARTE
{
	RIEN = 0,
	CARREAU_1 = 1,
	CARREAU_2 = 2,
	CARREAU_3 = 3,
	CARREAU_4 = 4,
	CARREAU_5 = 5,
	CARREAU_6 = 6,
	CARREAU_7 = 7,
	CARREAU_8 = 8,
	CARREAU_9 = 9,
	CARREAU_10 = 10,
	CARREAU_v = 11,
	CARREAU_d = 12,
	CARREAU_r = 13,
	COEUR_1 = 14,
	COEUR_2 = 15,
	COEUR_3 = 16,
	COEUR_4 = 17,
	COEUR_5 = 18,
	COEUR_6 = 19,
	COEUR_7 = 20,
	COEUR_8 = 21,
	COEUR_9 = 22,
	COEUR_10 = 23,
	COEUR_v = 24,
	COEUR_d = 25,
	COEUR_r = 26,
	TREFLE_1 = 27,
	TREFLE_2 = 28,
	TREFLE_3 = 29,
	TREFLE_4 = 30,
	TREFLE_5 = 31,
	TREFLE_6 = 32,
	TREFLE_7 = 33,
	TREFLE_8 = 34,
	TREFLE_9 = 35,
	TREFLE_10 = 36,
	TREFLE_v = 37,
	TREFLE_d = 38,
	TREFLE_r = 39,
	PIQUE_1 = 40,
	PIQUE_2 = 41,
	PIQUE_3 = 42,
	PIQUE_4 = 43,
	PIQUE_5 = 44,
	PIQUE_6 = 45,
	PIQUE_7 = 46,
	PIQUE_8 = 47,
	PIQUE_9 = 48,
	PIQUE_10 = 49,
	PIQUE_v = 50,
	PIQUE_d = 51,
	PIQUE_r = 52
}CARTE;

const char* getnamecarte(enum CARTE c) 
{
   switch (c) 
   {
   	case RIEN: return "";
    case CARREAU_1: return "CARREAU_1";
	case CARREAU_2: return "CARREAU_2";
	case CARREAU_3: return "CARREAU_3";
	case CARREAU_4: return "CARREAU_4";
	case CARREAU_5: return "CARREAU_5";
	case CARREAU_6: return "CARREAU_6";
	case CARREAU_7: return "CARREAU_7";
	case CARREAU_8: return "CARREAU_8";
	case CARREAU_9: return "CARREAU_9";
	case CARREAU_10: return "CARREAU_10";
	case CARREAU_v: return "CARREAU_v";
	case CARREAU_d: return "CARREAU_d";
	case CARREAU_r: return "CARREAU_r";
	case COEUR_1: return "COEUR_1";
	case COEUR_2: return "COEUR_2";
	case COEUR_3: return "COEUR_3";
	case COEUR_4: return "COEUR_4";
	case COEUR_5: return "COEUR_5";
	case COEUR_6: return "COEUR_6";
	case COEUR_7: return "COEUR_7";
	case COEUR_8: return "COEUR_8";
	case COEUR_9: return "COEUR_9";
	case COEUR_10: return "COEUR_10";
	case COEUR_v: return "COEUR_v";
	case COEUR_d: return "COEUR_d";
	case COEUR_r: return "COEUR_r";
	case TREFLE_1: return "TREFLE_1";
	case TREFLE_2: return "TREFLE_2";
	case TREFLE_3: return "TREFLE_3";
	case TREFLE_4: return "TREFLE_4";
	case TREFLE_5: return "TREFLE_5";
	case TREFLE_6: return "TREFLE_6";
	case TREFLE_7: return "TREFLE_7";
	case TREFLE_8: return "TREFLE_8";
	case TREFLE_9: return "TREFLE_9";
	case TREFLE_10: return "TREFLE_10";
	case TREFLE_v: return "TREFLE_v";
	case TREFLE_d: return "TREFLE_d";
	case TREFLE_r: return "TREFLE_r";
	case PIQUE_1: return "PIQUE_1";
	case PIQUE_2: return "PIQUE_2";
	case PIQUE_3: return "PIQUE_3";
	case PIQUE_4: return "PIQUE_4";
	case PIQUE_5: return "PIQUE_5";
	case PIQUE_6: return "PIQUE_6";
	case PIQUE_7: return "PIQUE_7";
	case PIQUE_8: return "PIQUE_8";
	case PIQUE_9: return "PIQUE_9";
	case PIQUE_10: return "PIQUE_10";
	case PIQUE_v: return "PIQUE_v";
	case PIQUE_d: return "PIQUE_d";
	case PIQUE_r: return "PIQUE_r";
     
   }
}

typedef struct Hand_of_other_player
{
	CARTE c1;
	CARTE c2;
	
}Hand_of_other_player;


typedef struct Score
{
	int score1;
	int score2;
}Score;


int randomF( int MIN, int MAX)
{  
   int nbs_aleatoire;
   nbs_aleatoire = (rand() % (MAX - MIN + 1)) + MIN;
   return nbs_aleatoire;
  
}

CARTE input_carte(void)
{

	printf("\n");
	
	printf("Carreau = 0\nCoeur = 1\nTrefle = 2\nPique = 3\n");
	int couleur;
	scanf("%d", &couleur);

	printf("\n");
	printf("<1> = 1\n<2> = 2\n<3> = 3\n<n> = n\n<valet> = 11\n<dame> = 12\n<roi> = 13\n");
	int motif;
	scanf("%d", &motif);

	CARTE c = (couleur*13) + motif;
	return c;
}

int choisir_carte_aleatoirement(CARTE *tas_de_carte)
{
	
	int carte_restant_tas = 52;
	for (int i = 0; i < 52; ++i)
	{
		if(*(tas_de_carte + i) == 0)
		{
			carte_restant_tas -= 1;
		}
	}

	


// choisir une carte aleatoirement dans le tas de carte !
	int compteur_u = 0;
	int carte_disponible = 0;

	int nbs_ale = randomF(1,carte_restant_tas);
	
	for (int i = 0; i < 52; ++i)
	{
		if(*(tas_de_carte + i) == 1)
		{
			compteur_u += 1;
			if (compteur_u == nbs_ale)
			{	
				*(tas_de_carte + i) = 0;
				CARTE retour = i + 1;  // car c'est une carte de 1 a 52 pas de 0 a 21
				return retour;
			}
		}
		
	}

}








// en pourcent, a l'unité près !
float win_proba(int nbs_joueur, int nbs_carte, CARTE *myhands, CARTE *inthemiddle, int NBS_PARTIE)
{	
	nbs_joueur -= 1;
	CARTE tas_de_carte[52];
	


	


	




	Hand_of_other_player *player = NULL;		//creation du pointeur 

	//allocation memoir, creation d'un tableau dynamique !
	player = malloc(sizeof(Hand_of_other_player) * nbs_joueur);
	if(player == NULL){
		exit(1);
	}



	Score *score = NULL;		//creation du pointeur 

	//allocation memoir, creation d'un tableau dynamique !
	score = malloc(sizeof(Score) * nbs_joueur+1);
	if(score == NULL){
		exit(1);
	}

	float nbs_fois_best_hand = 0;
	



	for (int i = 0; i < NBS_PARTIE; ++i) 		// boucle de monte carlos !
	{	
		float var = (float)i/NBS_PARTIE;
		if ( (NBS_PARTIE/100) != 0 )
		{
			int nbs_dd = NBS_PARTIE;
			if (i % (nbs_dd /100) == 0)
			{	
				printf("chargement : %.f \n",var*100);
			}
		}
		


		/*
		printf("\n");
		printf("=====================================================================\n");
		printf("boucle de monte carlos\n");
		printf("=====================================================================\n");
		printf("\n");
		*/

		// initialisation 
		for (int i = 0; i < 52; ++i)
		{
			tas_de_carte[i] = 1; // toute les cartes existes !
		}

		tas_de_carte[ *(myhands + 0) -1] = 0; // j'enleve les carte de mon tas de carte (celui que je distribue !)
		tas_de_carte[ *(myhands + 1) -1] = 0;

		for (int i = 0; i < nbs_carte; ++i)		// j'enleve les carte qui sont deja au milieux !
		{
			tas_de_carte[ *(inthemiddle + i) -1] = 0;
		}


		// END initialisation
		
		//printf("carte du joueur moi -> %s %s \n",getnamecarte(*(myhands + 0)) , getnamecarte(*(myhands + 1)) );
		
		
		// distribution des cartes au joueur !
		for (int i = 0; i < nbs_joueur; ++i)
		{
			
			(*(player + i)).c1 = choisir_carte_aleatoirement(tas_de_carte);
			
			(*(player + i)).c2 = choisir_carte_aleatoirement(tas_de_carte);
			
			//printf("carte du joueur %d -> %s %s \n",i+1,getnamecarte((*(player + i)).c1),getnamecarte((*(player + i)).c2));
			
		}

		
	


		int jeu_temp_in_the_middle[5];// creation des cartes temporaire au centre 
		for (int i = 0; i < nbs_carte; ++i)
		{
			jeu_temp_in_the_middle[i] = *(inthemiddle + i);
		} 

		// tirage des cartes restant au centre !
		for (int i = nbs_carte; i < 5; ++i)
		{
			jeu_temp_in_the_middle[i] = choisir_carte_aleatoirement(tas_de_carte);
		}
		/*
		printf("\n");
		printf("au centre:\n");
		
		for (int i = 0; i < 5; ++i)
		{
			printf("%s ",getnamecarte(jeu_temp_in_the_middle[i]));
		}
		printf("\n");
		*/


		/*
		for (int i = 0; i < 52; ++i)
		{	
			printf("%s -> %d\n",getnamecarte(i+1),tas_de_carte[i]);
		}
		*/

		// test du meilleur jeu ! =====================
		CARTE look[7] = {0,0,0,0,0,0,0};

		/*

			deroulement
			-> detecter le scors des cartes au milieux du plateau !
			-> detecter le score total des joueurs !
			-> soustraire ce score du score du plateau 
			
			-> si egalité, prendre le joueur avec la meilleur main (comparé carte 1, si egalité comparé carte 2)
			-> si encore, égalité, declaré la partie perdu !

Au Hold'em vous devez faire la meilleure main possible en utilisant n'importe quelle combinaison entre vos deux cartes 
privatives et les cinq communes sur le tableau (le board).

Vous pouvez donc utiliser une de vos cartes ou les deux, ou même aucune, pour constituer la meilleure combinaison possible. 
Voici quelques règles sur comment évaluer une main de poker gagnante :

		*/
		
		for (int i = 0; i < nbs_joueur+1; ++i)
		{
			(*(score + i)).score1 = 0;
			(*(score + i)).score2 = 0;
		}


		for (int p = 0; p < nbs_joueur+1; ++p) // boucle pour tout les joueurs !?
		{	
			/*
			printf("\n");
			printf("joueurs: %d\n", p);
			printf("\n");
			*/

			if (p == 0)
			{
				look[0] = (*(myhands + 0));
				look[1] = (*(myhands + 1));
				look[2] = jeu_temp_in_the_middle[0];
				look[3] = jeu_temp_in_the_middle[1];
				look[4] = jeu_temp_in_the_middle[2];
				look[5] = jeu_temp_in_the_middle[3];
				look[6] = jeu_temp_in_the_middle[4];
			}
			else
			{
				look[0] = (*(player + p-1)).c1;
				look[1] = (*(player + p-1)).c2;
				look[2] = jeu_temp_in_the_middle[0];
				look[3] = jeu_temp_in_the_middle[1];
				look[4] = jeu_temp_in_the_middle[2];
				look[5] = jeu_temp_in_the_middle[3];
				look[6] = jeu_temp_in_the_middle[4];
			}


			
			/*
			for (int i = 0; i < 7; ++i)
			{
				printf("look : %d\n",look[i]);
			}
			*/

			CARTE look_suite[7];	// creation d'un look avec seulement les chiffre
			for (int i = 0; i < 7; ++i)
			{
				if(look[i] % 13 == 0) 
				{
					look_suite[i] = 13;
				}
				else if(look[i] % 13 == 1) // l'as vaut 14
				{
					look_suite[i] = 14;
				}
				else
				{
					look_suite[i] = look[i] % 13;
				}
				
			}
			/*
			for (int i = 0; i < 7; ++i)
			{
				printf("look suite : %d\n",look_suite[i]);
			}
			*/


			// =========================================debut detection couleur !

			int liste_carreau[7] = {-1,-1,-1,-1,-1,-1,-1};
			int liste_coeur[7] = {-1,-1,-1,-1,-1,-1,-1};
			int liste_trefle[7] = {-1,-1,-1,-1,-1,-1,-1};
			int liste_pique[7] = {-1,-1,-1,-1,-1,-1,-1};

			int indice_carreau[7] = {-1,-1,-1,-1,-1,-1,-1};
			int indice_coeur[7] = {-1,-1,-1,-1,-1,-1,-1};
			int indice_trefle[7] = {-1,-1,-1,-1,-1,-1,-1};
			int indice_pique[7] = {-1,-1,-1,-1,-1,-1,-1};


			int cpt_carreau = 0;
			int cpt_coeur = 0;
			int cpt_trefle = 0;
			int cpt_pique = 0; 
				for (int i = 0; i < 7; ++i) // detection signe
				{
					
					if((look[i]-1) / 13 == 0)
					{
						liste_carreau[cpt_carreau] = look[i];
						indice_carreau[cpt_carreau] = i;
						cpt_carreau += 1;

					}
					else if((look[i]-1) / 13 == 1)
					{
						liste_coeur[cpt_coeur] = look[i];
						indice_coeur[cpt_coeur] = i;
						cpt_coeur += 1;

					}
					else if((look[i]-1) / 13 == 2)
					{
						liste_trefle[cpt_trefle] = look[i];
						indice_trefle[cpt_trefle] = i;
						cpt_trefle +=1;

					}
					else if ((look[i]-1) / 13 == 3)
					{	
						liste_pique[cpt_pique] = look[i];
						indice_pique[cpt_pique] = i;
						cpt_pique += 1;
					}

				}



			/*
			printf("cpt_carreau %d\n", cpt_carreau);
			printf("cpt_coeur %d\n", cpt_coeur);
			printf("cpt_trefle %d\n", cpt_trefle);
			printf("cpt_pique %d\n", cpt_pique);
			*/

			int indice_couleur[7] = {-1,-1,-1,-1,-1,-1,-1};
			CARTE temp888[7] = {-1,-1,-1,-1,-1,-1,-1};	// detection si suite et mise de la couleur dans temp888
			int detc_couleur = 0;

			if (cpt_carreau >= 5)
			{
				for (int i = 0; i < 7; ++i)
				{
					temp888[i] = liste_carreau[i];
					indice_couleur[i] = indice_carreau[i];
					detc_couleur = 1;
				}
				
			}
			else if(cpt_coeur >= 5)
			{
				for (int i = 0; i < 7; ++i)
				{
					temp888[i] = liste_coeur[i];
					indice_couleur[i] = indice_coeur[i];
					detc_couleur = 1;
				}
				
			}
			else if(cpt_trefle >= 5)
			{
				for (int i = 0; i < 7; ++i)
				{
					temp888[i] = liste_trefle[i];
					indice_couleur[i] = indice_trefle[i];
					detc_couleur = 1;
				}
				
			}
			else if(cpt_pique >= 5)
			{
				for (int i = 0; i < 7; ++i)
				{
					temp888[i] = liste_pique[i];
					indice_couleur[i] = indice_pique[i];
					detc_couleur = 1;
				}
				
			}
			/*
			for (int i = 0; i < 7; ++i)
			{
				printf("indice couleur %d\n",indice_couleur[i]);
			}
			*/
						// transformation des cartes look_chiffre en juste le numero !
			if (detc_couleur == 1)
			{
				
				CARTE look_temp_couleur[7] = {0,0,0,0,0,0,0};

				for (int i = 0; i < 7; ++i)
				{
					look_temp_couleur[i] = look_suite[i];			
				}
					//classer du plus petit au plus grand 

				




				int ma_couleur[7] = {0,0,0,0,0,0,0};



				int temp5 = 20;
				int indice_temp5 = 0;
				for (int k = 0; k < 7; ++k)
				{
					for (int i = 0; i < 7; ++i) 
					{
						if(look_temp_couleur[i] < temp5)
						{
							temp5 = look_temp_couleur[i];
							indice_temp5 = i;
						}
					}
					ma_couleur[k] = temp5;
					temp5 = 20;
					look_temp_couleur[indice_temp5] = 20;
				}

				for (int i = 0; i < 7; ++i)
				{
					if (ma_couleur[i] == 20)
					{
						ma_couleur[i] = -1;
					}
				}
				/*
				printf("couleur detecter ! \n");
				*/

				/*
				for (int i = 0; i < 7; ++i)
				{
					printf("ma couleur %d\n",ma_couleur[i]);
				}
				*/

				int hauteur_c1 = 0;
				int hauteur_c2 = 0;

				for (int i = 0; i < 7; ++i)
				{
					if (indice_couleur[i] == 0)
					{
						hauteur_c1 = look_suite[0];
					}
					if (indice_couleur[i] == 1)
					{
						hauteur_c2 = look_suite[1];
					}
				}

				if (hauteur_c1 > hauteur_c2)
				{
					
					(*(score + p)).score1 = 66 + hauteur_c1 -2;
					(*(score + p)).score2 = 66 + hauteur_c2 -2;
				}
				else
				{
					
					(*(score + p)).score2 = 66 + hauteur_c1 -2;
					(*(score + p)).score1 = 66 + hauteur_c2 -2;
				}


		


											
			}


			// ==================================fin couleur


			// ==================================debut suite

			

			
			

			CARTE look_temp[7];
			for (int i = 0; i < 7; ++i)
			{
				look_temp[i] = look_suite[i];
			}

			int indice_suite[7] = {-1,-1,-1,-1,-1,-1,-1};
			CARTE look_trie[7] = {0,0,0,0,0,0,0};
			int temp96 = 20;
			int indice_temp23 = 0;
			for (int k = 0; k < 7; ++k)
			{
				for (int i = 0; i < 7; ++i)       //classer du plus petit au plus grand 
				{
					if(look_temp[i] < temp96)
					{
						temp96 = look_temp[i];
						indice_temp23 = i;
					}
				}
			look_trie[k] = temp96;
			indice_suite[k] = indice_temp23;
			temp96 = 20;
			look_temp[indice_temp23] = 20;
			}

			/*
			for (int i = 0; i < 7; ++i)
			{
				printf("look trie : %d\n",look_trie[i]);
			}
			*/
			
			

			

			int indice_le_plus_grand_de_la_suite = 0;
			int cpt4 = 0;							//detection suite !
			int le_plus_gros_cpt4 = 0;
			for (int i = 6; i >= 1; --i)
			{
				if(look_trie[i] - look_trie[i-1] == 1)
				{
					if (cpt4 == 0)
					{
						indice_le_plus_grand_de_la_suite = i;
					}
					
					cpt4 +=1;
				}
				if (le_plus_gros_cpt4 < cpt4)
				{
					le_plus_gros_cpt4 = cpt4;
				}
				if (look_trie[i] - look_trie[i-1] > 1)
				{	
					
					cpt4 = 0;
				}
			}

			cpt4 = le_plus_gros_cpt4;
			if (cpt4 >= 4)
			{	
				/*
				printf("detection d'une suite !\n");
				printf("meilleure carte de la suite: %d\n",look_trie[indice_le_plus_grand_de_la_suite]);
				*/
				if (detc_couleur == 1)  // si couleur detecter



				{
					// alors il y a suite et couleur ! donc potentiellement QF 

					//il faut que se soit les memes !

					for (int i = 6; i > indice_le_plus_grand_de_la_suite; --i)
					{
						indice_suite[i] = -1;
					}
					/*
					for (int i = 0; i < 7; ++i)
					{
						printf("indice suite %d\n",indice_suite[i]);
					}
					*/

					
					int cpt_same_indice = 0;
					int indice_quinte_flush[7] = {-1,-1,-1,-1,-1,-1,-1};
					for (int k = 0; k < 7; ++k)
					{
						for (int i = 0; i < 7; ++i)
						{
							if ( (indice_couleur[k] == indice_suite[i]) && (indice_couleur[k] != -1))
							{
								indice_quinte_flush[k] = indice_couleur[k];
								cpt_same_indice++;
							}						
						}	
					}

					if (cpt_same_indice >= 5)
					{

						// il y a au moins 5 carte qui sont a la fois une suite et une couleur !
						
						// quinte flush !

						/*
						for (int i = 0; i < 7; ++i)
						{
							printf("indice quinte flush: %d\n", indice_quinte_flush[i]);
						}
						*/

						int quinte_flush_royale = 0;
						int best_carte_quinte_flush = 0;
						for (int i = 0; i < 7; ++i)
						{
							if (indice_quinte_flush[i] != -1)
							{	
								if(best_carte_quinte_flush < look_suite[indice_quinte_flush[i]])
								{
									best_carte_quinte_flush = look_suite[indice_quinte_flush[i]];
								}
								if (look_suite[indice_quinte_flush[i]] == 14) // si il y a un as dans la quinte flush 
								{
									// alors c'est une quinte flush royale !
									
									//printf("quinte flush royale !!!!\n");
									
									(*(score + p)).score1 = 130;
									(*(score + p)).score2 = 130;
									quinte_flush_royale = 1;
								}
								
							}
						}
						if (quinte_flush_royale == 0)
						{
							/*
							printf("quinte flush !\n");
							*/
							(*(score + p)).score1 = 105+best_carte_quinte_flush;
							(*(score + p)).score2 = 105+best_carte_quinte_flush;
							
						}


					}


				}else
				{	
					// il y a juste une suite !
					(*(score + p)).score1 = 53 + look_trie[indice_le_plus_grand_de_la_suite] -2 ;
					(*(score + p)).score2 = 53 + look_trie[indice_le_plus_grand_de_la_suite] -2 ;
				}

				


			}



			// =======================fin detection suite

			// ========================debut detection meme carte !

			int cpt00[7] = {0,0,0,0,0,0,0};
			int indice_cpt00[7] = {0,0,0,0,0,0,0};
			int cpt_cpt00 = 0;
			for (int i = 6; i >= 1; --i)
			{	
				if(look_trie[i] - look_trie[i-1] == 0)
				{
					cpt00[cpt_cpt00]++;
					indice_cpt00[cpt_cpt00] = i;
				}
				else
				{
					cpt_cpt00++;
				}
			}
			int a_carre = 0;
			int a_brelan[2] = {0,0};
			int nbs_brelan = 0;
			int a_pair[3] = {0,0,0};
			int nbs_pair = 0;
			
			/*
			for (int i = 0; i < 7; ++i)
			{
				printf("cpt00: %d\n",cpt00[i]);
			}
			for (int i = 0; i < 7; ++i)
			{
				printf("indice cpt00: %d \n",indice_cpt00[i]);
			}
			*/

			int potentiel_pair = 0;
			int potentiel_brelan = 0;

			for (int i = 0; i < 7; ++i)
			{
				if (cpt00[i] == 2)
				{	
					if (nbs_brelan < 1)
					{
						a_brelan[nbs_brelan] = look_trie[indice_cpt00[i]];
						potentiel_brelan = a_brelan[nbs_brelan];
						/*
						printf("brelan a : %d\n",a_brelan[nbs_brelan]);
						*/
						if(40 + a_brelan[nbs_brelan] - 2 > (*(score + p)).score1)
						{
							(*(score + p)).score1 = 40 + a_brelan[nbs_brelan] - 2;
							(*(score + p)).score2 = 40 + a_brelan[nbs_brelan] - 2;
						}	
						nbs_brelan +=1;	
					}
									
				}
				else if (cpt00[i] == 3)
				{
					a_carre = look_trie[indice_cpt00[i]];
					/*
					printf("carre a : %d\n",a_carre);
					*/
					if ( 92 + a_carre - 2 > (*(score + p)).score1 )
					{
						(*(score + p)).score1 = 92 + a_carre - 2;
						(*(score + p)).score2 = 92 + a_carre - 2;
					}
					
				}
				else if (cpt00[i] == 1)
				{	
					if (nbs_pair == 0)
					{
						a_pair[nbs_pair] = look_trie[indice_cpt00[i]];
						potentiel_pair = a_pair[nbs_pair];
						/*
						printf("pair a : %d\n", a_pair[nbs_pair]);		
						*/
						if (14 + a_pair[nbs_pair] - 2 > (*(score + p)).score1)
						{
							(*(score + p)).score1 = 14 + a_pair[nbs_pair] - 2;	
							(*(score + p)).score2 = 14 + a_pair[nbs_pair] - 2;	
						}
					}
					if (nbs_pair == 1)
					{
						a_pair[nbs_pair] = look_trie[indice_cpt00[i]];
						/*
						printf("deuxieme pair a : %d\n", a_pair[nbs_pair]);
						*/
						if (40 > (*(score + p)).score1)
						{
							(*(score + p)).score1 = (*(score + p)).score1 + 13;	
							(*(score + p)).score2 = 27 + a_pair[nbs_pair] - 2;	
						}
					}
					nbs_pair += 1;
					
				}

				

			}

		if (nbs_pair >= 1 && nbs_brelan >= 1)
			{
				/*
				printf("full, brelan a : %d et pair a : %d\n",potentiel_brelan, potentiel_pair);
				*/
				if (79 + potentiel_brelan -2 > (*(score + p)).score1 )
				{
					(*(score + p)).score1 = 79 + potentiel_brelan -2;	
					(*(score + p)).score2 = 79 + potentiel_pair -2;	
				}
			}

			

		// plus haute carte !




		if ((*(score + p)).score1 == 0)
		{
			if (look[0] > look[1])
			{
				(*(score + p)).score1 = look_suite[0]-2;	
				(*(score + p)).score2 = look_suite[1]-2;	
			}
			else
			{
				(*(score + p)).score1 = look_suite[1]-2;	
				(*(score + p)).score2 = look_suite[0]-2;	
			}


		}





		/*
		printf("\n");
		printf("\n");
		printf("SCORE1 : %d\n", (*(score + p)).score1 );
		printf("SCORE2 : %d\n", (*(score + p)).score2 );
		*/
			


		}


		// gerer les egalité
		// gerer si meme couleur !
	
	int win = 1;
	int egalite = 0;
	for (int i = 1; i < nbs_joueur+1; ++i)
	{	
		if( (*(score + i)).score1 > (*(score + 0)).score1 ) // si n'importe qui a un meilleur score que moi
		{
			// j'ai perdu !
			win = 0;
		}
		else if ( (*(score + i)).score1 == (*(score + 0)).score1 ) // je verifie qu'on n'est pas le meme score
		{
			if ( (*(score + i)).score2 > (*(score + 0)).score2 ) // je verifie que cette personne na pas un meilleur score que moi
			{
				//j'ai perdu !
				win = 0;
			}
			else if ( (*(score + i)).score2 == (*(score + 0)).score2  )
			{
				egalite = 1;
				win = 1;
			}

		}
	}
	if (win == 1)
	{	
		/*
		printf("WIN\n");
		*/
		nbs_fois_best_hand +=1;
	}
	else if (egalite == 1)
	{
		nbs_fois_best_hand +=1;

	}
	else
	{
		/*
		printf("LOOSE\n");
		*/
	}
	



	


	



	} // fin boucle monte carlos

	free(player);
	free(score);

	printf("nbs_fois_best_hand: %f\n", nbs_fois_best_hand);
	printf("nombre de partie: %d\n",NBS_PARTIE);


return nbs_fois_best_hand;
}

int main(void)
{		
	//initialisation du seed
	srand(time(NULL));
	// et petit random, pour initialisé les premieres valeurs !
	for (int i = 0; i < 100; ++i)
	{
		randomF(0,52);
	}
	int NBS_PARTIE = 0;
	printf("combien de partie simule ?\n");
	scanf("%d",&NBS_PARTIE);



	int nbs_joueur;
	CARTE myhands[2] = {0,0};

	printf("combien de joueur ?\n");
	scanf("%d",&nbs_joueur);


	// recuper les deux cartes se sa main

	printf("1er carte de votre main : \n");
	
	myhands[0] = input_carte();

	printf("2eme carte de votre main : \n"); 

	myhands[1] = input_carte();

	printf("\n=================================================\n");
	printf("votre main: %s et %s\n",getnamecarte(myhands[0]),getnamecarte(myhands[1]) );
	printf("\n=================================================\n");

	//enregistrement des cartes au centre de la table !

	printf("nombre de carte au centre ?\n");
	int nbs_carte;
	scanf("%d",&nbs_carte);

	printf("\nqui sont ?\n");

	CARTE inthemiddle[5] = {0,0,0,0,0};
	for (int i = 0; i < nbs_carte; ++i)
	{
		inthemiddle[i] = input_carte(); 
	}
	printf("\n=================================================\n");
	printf("votre main: %s et %s\n",getnamecarte(myhands[0]),getnamecarte(myhands[1]) );
	printf("sur la table: %s , %s , %s , %s , %s \n" , getnamecarte(inthemiddle[0]) , getnamecarte(inthemiddle[1]), getnamecarte(inthemiddle[2]), getnamecarte(inthemiddle[3]), getnamecarte(inthemiddle[4]));
	printf("\n=================================================\n");

	float win = win_proba(nbs_joueur, nbs_carte, myhands, inthemiddle,NBS_PARTIE);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	float proba = win / NBS_PARTIE * 100;
	
	printf("==============================================================\n");
	printf("probabilite de gagne : %f  \n", proba );
	printf("==============================================================\n");
	int fin;
	scanf("%d", &fin);


	return 0;
}