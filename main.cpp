#include "main.hpp"
#include "sudoko.cpp"

int main()
{
    Sudoko monsud("test2.txt");
    // monsud.Afficher_Sud();

    // cout<<"/********************** R E S O U D R E *********************/"<<endl;
    auto start = chrono::high_resolution_clock::now();
    monsud.Resoudre_Sudoko();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "Temps d'execution : " << duration.count() << " milliseconds" <<endl;
    monsud.Afficher_Sud();
    

}
