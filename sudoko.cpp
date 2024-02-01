#include "main.hpp"
#include "sudoko.hpp"


Sudoko::Sudoko(const string &nomfichier)
{
    ifstream fichier(nomfichier);
    if(!fichier.is_open())
    {
        cout<<"Impossible d ouvrir le fichier"<<endl;
        return;
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(!(fichier >> Matrice[i][j]))
            {
                cout<<"Erreur lectur fichier!"<<endl;
                return;
            }
        }
    }
    fichier.close();
}

bool Sudoko::Chercher_Case_Vide(int &ligne,int &col)
{
    for(ligne=0;ligne<9;ligne++)
    {
        for(col=0;col<9;col++)
        {
            if(Matrice[ligne][col] == 0) return true;
        }
    }
    return false;
}

bool Sudoko::Resoudre_Sudoko()
{
    int ligne,colonne;
    if(!Chercher_Case_Vide(ligne,colonne)) // aucune case n est vide => sudoko resolu
        return true;
    for(int i=1;i<10;i++)
    {
        if((VerifierCase(ligne,colonne,i)) && (VerifierColonne(colonne,i)) &&
            VerifierLigne(ligne,i))
            {
                Matrice[ligne][colonne]=i;
                if(Resoudre_Sudoko()) return true;
                Matrice[ligne][colonne]=0;
            }
    }
    return false;
}

bool Sudoko::VerifierLigne(int l,int val)
{
    for(int j=0;j<9;j++)
    {
        if(Matrice[l][j] == val) return false;
    }
    return true;//vide
}

bool Sudoko::VerifierColonne(int c,int val)
{
    for(int i=0;i<9;i++)
    {
        if(Matrice[i][c]==val) return false;//rempli
    }
    return true;//vide
}

bool Sudoko::VerifierCase(int i,int j,int val)
{
    int l,c;
    if(i<3) l=0;
    else if(i<6) l=3;
    else if(i<9)l=6;
    if(j<3) c=0;
    else if(j<6) c=3;
    else if(j<9)c=6;
    for(int ligne=l;ligne<(l+3);ligne++)
    {
        for(int colonne=c;colonne<(c+3);colonne++)
        {
            if(Matrice[ligne][colonne] == val) return false;//rempli
        }
    }
    return true;//vide

}

void Sudoko::Afficher_Sud()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++) 
        {
            if((j%3 ==0) && (j!=0)) cout<<"   ";
            cout<<Matrice[i][j]<<" ";
        }
        cout<<endl;
        if(((i+1)%3 ==0) && (i!=0)) cout<<endl;
    }
    
}
bool Sudoko::ArretBoucle(int tab[10])
{
    for(int i=0;i<10;i++)
    {
        if(tab[i] == -1) return true;
    }
    return false;
}
