#ifndef SRC_SUDOKO_H_
#define SRC_SUDOKO_H_

class Sudoko{
    private:
        int Matrice[9][9];
        int ver[10];
    public:
        Sudoko(const string &);
        void Afficher_Sud();
        bool Chercher_Case_Vide(int &,int &);
        bool Resoudre_Sudoko();
        bool Res_Aleatoire( int*);
        bool VerifierCase(int,int,int);//i,j,val
        bool VerifierLigne(int,int);
        bool VerifierColonne(int,int);
        bool ArretBoucle(int*);
        void Generer_Sudoko();
};

#endif