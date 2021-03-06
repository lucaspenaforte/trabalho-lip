#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX=40;
using namespace std;

void imprimir_matriz(char [][MAX], int,int );

void preenche_matriz(char [][MAX], int ,int ,char );

void criar_bomba(char [][MAX], int ,int ,int );

void bomba_proxima( char m[][MAX], int ordemL, int ordemC);

void soma_posicao(char m[][MAX], int ordemL, int ordemC, int , int );

void descubrir (char m[][MAX], char m2[][MAX], int ordemL, int ordemC, int , int  );



int main(){
    int escolha1,escolha2,dimL,dimC,L1,C1,Quant_mina=0;
    char matriz1[MAX][MAX], matriz2[MAX][MAX];
    cout<<"1.Novo jogo"<<endl;
    cout<<"2.Melhores tempos"<<endl;
    cout<<"3.Sair"<<endl;

    cout<<"digite sua escolha:"<<endl;
    cin>>escolha1;
    //system("cls");     // caso for linux "clear (para sumir o escrito na tela depois da escolha)
    if(escolha1==1){

        cout<<"1.Jogo Iniciante"<<endl;
        cout<<"2.Jogo Intermediario"<<endl;
        cout<<"3.Jogo Personalizado"<<endl;
        cout<<"4.Voltar"<<endl;

        cout<<"digite sua escolha:"<<endl;
        cin>>escolha2;

        if(escolha2==1)
        {
            cout<<"INICIANTE" <<endl;
            preenche_matriz(matriz1, 8,8,'.');

            imprimir_matriz(matriz1, 8,8);

            cout<<"matriz 2"<<endl;

            preenche_matriz(matriz2, 8,8,'0');

            criar_bomba( matriz2, 8,8, 10);

            bomba_proxima( matriz2, 8,8);

            imprimir_matriz(matriz2, 8,8);

            do{
                system("cls");
                imprimir_matriz(matriz1, 8,8);

                cout<<"descobrir a posicao, linha e coluna: "<<endl;
                cin>>L1>>C1;


                 matriz1[L1][C1] = matriz2[L1][C1];

                 cout<<matriz1[L1][C1];
                 if(matriz2[L1][C1]=='0'){

                    descubrir( matriz1, matriz2, dimL, dimC, L1, C1);
                    imprimir_matriz(matriz1, 8,8);
                 }

            }while(matriz2[L1][C1]!='*');
            cout<<"VOCE PERDEU O JOGO"<<endl;
            imprimir_matriz(matriz2, 8,8);
        }
        if(escolha2==2)
        {
            cout<<"INTERMEDIARIO"<<endl;
            preenche_matriz(matriz1, 16,16,'.');

            imprimir_matriz(matriz1, 16,16);

            cout<<"matriz 2"<<endl;

            preenche_matriz(matriz2, 16,16,'0');

            criar_bomba( matriz2, 16,16, 40);

            bomba_proxima( matriz2, 16,16);

            imprimir_matriz(matriz2, 16,16);

                do{
                system("cls");
                imprimir_matriz(matriz1, 16,16);

                cout<<"descobrir a posicao, linha e coluna: "<<endl;
                cin>>L1>>C1;


                 matriz1[L1][C1] = matriz2[L1][C1];

                 cout<<matriz1[L1][C1];
                 if(matriz2[L1][C1]=='0'){

                    descubrir( matriz1, matriz2, dimL, dimC, L1, C1);
                    imprimir_matriz(matriz1, 16,16);
                 }

            }while(matriz2[L1][C1]!='*');
            cout<<"VOCE PERDEU O JOGO"<<endl;
            imprimir_matriz(matriz2, 16,16);




        }
        if(escolha2==3)
        {
            cout<<"PERSONALIZADO"<<endl;
            cout<<"digite as dimensoes da matriz, linhas: "<<endl;
            cin>>dimL;
            cout<<"colunas: "<<endl;
            cin>>dimC;


            do{
                cout<<"digite a quantidade de minas: "<<endl;
                cin>>Quant_mina;
            }while(Quant_mina>(dimL*dimC)-10);

            preenche_matriz(matriz1, dimL,dimC,'.');

            imprimir_matriz(matriz1, dimL,dimC);

            cout<<"matriz 2"<<endl;

            preenche_matriz(matriz2, dimL,dimC,'0');

            criar_bomba( matriz2, dimL,dimC, Quant_mina);

            bomba_proxima( matriz2, dimL,dimC);

            imprimir_matriz(matriz2, dimL,dimC);

            do{
                system("cls");
                imprimir_matriz(matriz1, dimL,dimC);

                cout<<"descobrir a posicao, linha e coluna: "<<endl;
                cin>>L1>>C1;


                 matriz1[L1][C1] = matriz2[L1][C1];

                 cout<<matriz1[L1][C1];
                 if(matriz2[L1][C1]=='0'){

                    descubrir( matriz1, matriz2, dimL, dimC, L1, C1);
                    imprimir_matriz(matriz1, dimL,dimC);
                 }

            }while(matriz2[L1][C1]!='*');
            cout<<"VOCE PERDEU O JOGO"<<endl;
            imprimir_matriz(matriz2, dimL,dimC);


        }
        if(escolha2==4){


        }
    }//--------------------- FIM DAS ESCOLHAS 2== NIVEL DE DIFICULDADE-------------------
    if(escolha1==2){
        cout <<"MELHORES TEMPOS:"<<endl;
        cout<<" iniciante: "<<endl;
        cout<<"intermediario: "<<endl;


    }

    if(escolha1==3){

    }
} //-----------------FIM DA FUNÇÃO "INT MAIN"-----------------------


void imprimir_matriz(char m[][MAX], int ordemL, int ordemC){
   cout<<"    ";
   for(int i=0;i<ordemC;i++){
       cout<<"["<<i<<"]";
   }
   cout<<endl;
    for(int i=0; i<ordemL; i++){
        if(i<10){
            cout<<"["<<i<<"]  ";
        }
        else{
            cout<<"["<<i<<"] ";
        }

        for(int j=0; j<ordemC; j++){
                if(j>10){
                    cout<<m[i][j]<<"   ";
                }
                else{
            cout<<m[i][j]<<"  ";
                }
        }
        cout<<endl;
    }

}
void preenche_matriz(char m[][MAX], int ordemL, int ordemC,char caracter)
{
    for(int i=0; i<ordemL; i++)
    {
        for(int j=0; j<ordemC; j++)
        {
            m[i][j]=caracter;
        }
    }
}

void criar_bomba(char m[][MAX], int ordemL, int ordemC, int cont_bomba)
{
    srand(time(NULL));
    int sorteioI, sorteioJ;
    sorteioI=rand()%ordemL;
    sorteioJ=rand()%ordemC;
    while(cont_bomba>0)
    {
        while(m[sorteioI][sorteioJ]!='0')
        {
            sorteioI=rand()%ordemL;
            sorteioJ=rand()%ordemC;
        }
        m[sorteioI][sorteioJ]='*';
        cont_bomba--;
    }

}

void bomba_proxima( char m[][MAX], int ordemL, int ordemC)
{

    for(int i=0; i<ordemL; i++)
    {
        for (int j=0; j<ordemC; j++)
        {
            if(m[i][j]=='*')
            {
                soma_posicao(m, ordemL, ordemC, i, j);
            }
        }
    }


}
void soma_posicao(char m[][MAX], int ordemL, int ordemC, int i, int j ){

    if( (i-1>=0 && j-1>=0) && m[i-1][j-1]!='*' ){
        m[i-1][j-1]++;
    }
    if( (i-1>=0 && j>=0)  && m[i-1][j]!='*'){
        m[i-1][j]++;
    }
    if( (i-1>=0 && j+1<ordemC) && m[i-1][j+1]!='*'){
        m[i-1][j+1]++;
    }
    if( (i>=0 && j-1>=0) && m[i][j-1]!='*'){
        m[i][j-1]++;
    }
    if( (i>=0 && j+1<ordemC) && m[i][j+1]!='*'){
        m[i][j+1]++;
    }
    if( (i+1<ordemL && j-1>=0) && m[i+1][j-1]!='*'){
        m[i+1][j-1]++;
    }
    if( (i+1<ordemL && j>=0) && m[i+1][j]!='*'){
        m[i+1][j]++;
    }
    if( (i+1<ordemL && j+1>=0) && m[i+1][j+1]!='*'){
        m[i+1][j+1]++;
    }

}

void descubrir (char m[][MAX], char m2[][MAX], int ordemL, int ordemC, int i, int j){

    if(i-1>=0 && j-1>=0){
        m[i-1][j-1] = m2[i-1][j-1];

        if( m2[i-1][j-1]=='0'){
            m[i-1][j-1]='_';
        }
    }
    if(i-1>=0 && j>=0){
        m[i-1][j] = m2[i-1][j];

        if(m2[i-1][j]=='0'){
            m[i-1][j]='_';
        }
    }
    if(i-1>=0 && j+1>=0){
        m[i-1][j+1] = m2[i-1][j+1];

        if( m2[i-1][j+1]=='0'){
              m[i-1][j+1]='_';
        }
    }
    if(i>=0 && j-1>=0){
        m[i][j-1] = m2[i][j-1];

        if(m2[i][j-1]=='0'){
            m[i][j-1]='_';
        }
    }
    if(i>=0 && j>=0){
        if(m2[i][j]=='0'){
            m[i][j]='_';
        }

    }
    if(i>=0 && j+1>=0){
        m[i][j+1] = m2[i][j+1];
        if(m2[i][j+1]=='0'){
            m[i][j+1]='_';
        }
    }
    if(i+1>=0 && j-1>=0){
        m[i+1][j-1] = m2[i+1][j-1];
        if(m2[i+1][j-1]=='0'){
            m[i+1][j-1]='_';
        }
    }
    if(i+1>=0 && j>=0){
        m[i+1][j] = m2[i+1][j];
        if(m2[i+1][j]=='0'){
            m[i+1][j]='_';
        }
    }
    if(i+1>=0 && j+1>=0){
        m[i+1][j+1] = m2[i+1][j+1];
        if(m2[i+1][j+1]=='0'){
            m[i+1][j+1]='_';
        }
    }

}
