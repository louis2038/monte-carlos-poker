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
	int score;
	
}Hand_of_other_player;





int random( int MIN, int MAX)
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

	int nbs_ale = random(1,carte_restant_tas);
	
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
int win_proba(int nbs_joueur, int nbs_carte, CARTE *myhands, CARTE *inthemiddle)
{	
	nbs_joueur -= 1;
	CARTE tas_de_carte[52];
	


	


	




	Hand_of_other_player *player = NULL;		//creation du pointeur 

	//allocation memoir, creation d'un tableau dynamique !
	player = malloc(sizeof(Hand_of_other_player) * nbs_joueur);
	if(player == NULL){
		exit(1);
	}




	int nbs_fois_best_hand = 0;
	int nbs_de_partie = 1;

	
	for (int i = 0; i < nbs_de_partie; ++i) // boucle de monte carlos !
	{
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

		
		// distribution des cartes au joueur !
		for (int i = 0; i < nbs_joueur; ++i)
		{
			
			(*(player + i)).c1 = choisir_carte_aleatoirement(tas_de_carte);
			
			(*(player + i)).c2 = choisir_carte_aleatoirement(tas_de_carte);
			
			printf("carte du joueur %d -> %s %s \n",i,getnamecarte((*(player + i)).c1),getnamecarte((*(player + i)).c2));
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


		printf("au centre:\n");
		for (int i = 0; i < 5; ++i)
		{
			printf("%s ",getnamecarte(jeu_temp_in_the_middle[i]));
		}
		printf("\n");

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

		for (int i = 0; i < nbs_joueur; ++i)
		{
			look[0] = (*(player + i)).c1;
			look[1] = (*(player + i)).c2;
			look[2] = jeu_temp_in_the_middle[0];
			look[3] = jeu_temp_in_the_middle[1];
			look[4] = jeu_temp_in_the_middle[2];
			look[5] = jeu_temp_in_the_middle[3];
			look[6] = jeu_temp_in_the_middle[4];

			for (int i = 0; i < 7; ++i)
			{
				printf("look : %d\n",look[i] );
			}

			int cpt_carreau;
			int cpt_coeur;
			int cpt_trefle;
			int cpt_pique; 
			for (int i = 0; i < 7; ++i) // detection signe
			{

				if(look[i] / 13 == 0)
				{
					cpt_carreau += 1;
				}else if(look[i] / 13 == 1)
				{
					cpt_coeur += 1;
				}else if(look[i] / 13 == 2)
				{
					cpt_trefle +=1;
				}else
				{
					cpt_pique += 1;
				}

			}


			CARTE look_chiffre[7];	// creation d'un look avec seulement les chiffre
			for (int i = 0; i < 7; ++i)
			{
				if (look[i] % 13 == 0)
				{
					look_chiffre[i] = 13;
				}else
				{
					look_chiffre[i] = look[i] % 13;
				}
				
			}
			for (int i = 0; i < 7; ++i)
			{
				printf("look chiffre : %d\n",look_chiffre[i] );
			}

			CARTE look_trie[7];
			int temp5 = 20;
			int indice_temp5 = 0;
			for (int k = 0; k < 7; ++k)
			{
				for (int i = 0; i < 7; ++i)  //classer du plus petit au plus grand 
				{
					if(look_chiffre[i] < temp5)
					{
						temp5 = look_chiffre[i];
						indice_temp5 = i;
					}
				}
			look_trie[k] = temp5;
			temp5 = 20;
			look_chiffre[indice_temp5] = 20;
			}

			for (int i = 0; i < 7; ++i)
			{
				printf("look_trie : %d \n",look_trie[i]);
			}


			int le_plus_grand_de_la_suite = 0;
			int cpt4 = 0;			//detection suite !
			for (int i = 6; i >= 1; --i)
			{
				if(look_trie[i] - look_trie[i-1] == 1)
				{
					if (cpt4 == 0)
					{
						le_plus_grand_de_la_suite = look_trie[i];
					}
					cpt4 +=1;
				}
				if(look_trie[i] - look_trie[i-1] > 1)
				{
					cpt4 = 0;
				}
			}
			if (cpt4 >= 4)
			{
				// il y a une suite
				printf("suite !\n");

				if(le_plus_grand_de_la_suite == 13)
				{

				}




			}



			/*
			int de_combien_cela_se_suit;
			for (int i = 0; i < 7; ++i) // detection suite
			{
				look[i] % 13
			}
				}
*/

			


			


		}


	





	free(player);





	printf("win proba\n");

	return 0;

	} // fin boucle monte carlos

}
int main(void)
{	
	//initialisation du seed
	srand(time(NULL));
	// et petit random, pour initialisé les premieres valeurs !
	for (int i = 0; i < 100; ++i)
	{
		random(0,52);
	}
	



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

	int proba = win_proba(nbs_joueur, nbs_carte, myhands, inthemiddle);




	return 0;
}