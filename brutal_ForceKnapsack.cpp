#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

int getMaiorValor(int n, int p[], int v[], int c, int i){

    int add_item, del_item;
 
    if(i == n || c <= 0){//ultimo item ou maxima capacidade
        return 0;
    }


    if(p[i] <= c){ //peso do item atual é menor ou igual a capacidade
        add_item = getMaiorValor(n, p, v, c-p[i], i+1) + v[i];//capaciade diminiu pois item é incluido, i++ = prox item

        del_item = getMaiorValor(n, p, v, c, i+1);

        return max(add_item, del_item);

    }else{
        del_item = getMaiorValor(n, p, v, c, i+1);//o item é maior do que a capacidade, apenas acha o valor sem inlcluir
        return del_item;
    }
}



int main(void){


    ifstream teste;

    int i  = 0;
    int n = 0;//numermo de itenss
    int c = 0;// capacidade maxima da mochila

    teste.open("teste.txt");
    if(teste.is_open()){
        teste >> n;
        teste >> c;
        cout << "Numero de itens = " << n << " Capacidade = " << c << endl;
        i++;
    }

    //int g = n;

    int p[n];//vetor com peso de cada item
    int v[n];//vetor com valor de cada item

    cout << n << " . " << n << endl;

    cout << i << endl;

    while(!teste.eof()){
        teste >> p[i];
        teste >> v[i];
        i++;
    }
    
    cout << "Resultado da somatoria = " << getMaiorValor (n, p, v, c, 0) << endl;

}
