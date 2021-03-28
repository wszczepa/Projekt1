#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

//Algorytm sortowania przez kopcowanie


void Kopcowanie(int tab[], int prawyIndeks, int i)
{
    int rodzic = i;
    int lewy = 2*i+ 1;
    int prawy= 2*i+ 2;

    //Jesli lewy indeks miesci sie w tablicy
    if(lewy < prawyIndeks){

        // Jesli lewe dziecko jest wieksze od rodzica
        if (tab[lewy] > tab[rodzic]){

        rodzic = lewy;         //zmiana indeksu rodzica
        }
    }
    //Jesli prawy indeks miesci sie w tablicy
    if(prawy < prawyIndeks){

        //Jesli prawe dziecko jest wieksze od rodzica
        if (tab[prawy] > tab[rodzic]){

        rodzic = prawy;        //zmiana indeksu rodzica
        }
    }

    //Jesli indeks został zmieniony to zamiana z odpowiednim dzieckiem
    if (rodzic != i) {

        int temp = tab[i];
        tab[i]=tab[rodzic];
        tab[rodzic]=temp;


        Kopcowanie(tab, prawyIndeks, rodzic);         // Sprawdza w kolejnej galezi
    }
}

void SortowaniePrzezKopcowanie(int tab[], int prawyIndeks)
{
    int i = prawyIndeks / 2;         //indeks ostatniego rodzica

    for (i ; i >= 0; i--){           //budowa kopca
        Kopcowanie(tab, prawyIndeks, i);
    }

    for (int p = prawyIndeks; p >= 0; p--) {

        int temp = tab[0];      //Zamiana korzenia(tab[0]-najwieksza liczba w tablicy) z ostatnim elementem tablicy
        tab[0]=tab[p];
        tab[p]=temp;
        prawyIndeks--;                  //Ostatni element jest na docelowej pozycji i mozna go usunaæ
        Kopcowanie(tab, p, 0);
    }
}

/*-----------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------*/


//Algorytm sortowanania przez scalanie

void scalanie(int tab[],int temp[], int lewa,int srodek, int prawa){


//Przepisanie tablicy do tablicy pomocniczej

    for(int i=lewa;i<=prawa;i++){

        temp[i]=tab[i];

    }

    int lPomoc=lewa;                                //indeks w docelowej tablicy
    int srPomoc=srodek+1;
    while(lewa<=srodek && srPomoc<=prawa){          //Dopoki któras z czesci tablicy sie nie skonczy

    //Jezeli liczba z lewej tablicy jest mniejsza lub rowna liczbie z prawej tablicy  przepisujemy ja do tablicy glownej
        if(temp[lewa]<=temp[srPomoc]){
            tab[lPomoc]=temp[lewa];
            lewa++;
        }

    //Jezeli liczba z lewej tablicy jest wieksza od liczby z tablicy prawej to przepisujemy liczbe z prawej tablicy do tablicy glownej
        else{
            tab[lPomoc]=temp[srPomoc];
            srPomoc++;
        }
        lPomoc++;
    }


//Jesli zostaly jakies elementy w lewej czesci tablicy to dopisuje reszte
    while(lewa<=srodek){
        tab[lPomoc]=temp[lewa];
        lPomoc++;
        lewa++;
    }

//Jesli zostaly jakies elementy w prawej czesci tablicy to dopisuje reszte
    while(srPomoc<=prawa){
        tab[lPomoc]=temp[srPomoc];
        lPomoc++;
        srPomoc++;
    }
    }

SortowaniePrzezScalanie(int tab[],int temp[], int lewa, int prawa){


if(prawa>lewa){

    int srodek=(prawa+lewa)/2;
    SortowaniePrzezScalanie(tab,temp,lewa,srodek);        //Dzielenie tablicy na dwie czesci do czasu, az beda jednoelementowe tablice
    SortowaniePrzezScalanie(tab,temp,srodek+1,prawa);     //srodek +1 zeby prawa tablica zaczynala sie od nastepnego elementu po elemencie srodkowym
    scalanie(tab,temp,lewa,srodek,prawa);
}

}

/*--------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------*/

//Algorytm sortowania szybkiego


void SortowanieSzybkie(int tab[], int lewy, int prawy)
{


	int l = lewy - 1;       //lewy indeks do przejscia po tablicy
    int p= prawy + 1;      //prawy indeks do przejscia po tablicy
    int temp;
	int punkt = tab[(lewy+prawy)/2]; // punkt odniesienia

    //Dopoki indeks lewy i prawy nie spotkaja sie
	while(l<=p)
	{
		//Dopoki nie znajdzie elementu wiekszego  od punktu odniesienie po jego lewej stronie w tablicy
		while(punkt>tab[++l]);

		//Dopoki nie znajdzie elementu mniejszego od punktu odniesienia po jego prawej stronie w tablicy
		while(punkt<tab[--p]);

		//Jesli indeks lewy jest mniejszy od prawego zamieniane sa ich wartosci
		if( l < p){

			temp=tab[l];
			tab[l]=tab[p];
			tab[p]=temp;
		}
	}
   //Jesli więcej niz jeden element w lewej czesci
	if(p > lewy)
	SortowanieSzybkie(tab, lewy, p);
    //Jesli wiecej niz jeden element w prawej czesci
	if(l < prawy)
	SortowanieSzybkie(tab, l, prawy);




}



int main()
{



        srand(time(NULL));

    int n,wybor;
    cout.setf(ios::fixed); //notacja zwykla, czyli nie wywali wyniku typu 1.175000e+003
    cout.precision(5); //liczba miejsc po przecinku, dokladnosc naszego wyniku
    clock_t start, koniec; //inicjacja zmiennych zegarowych



    int* tab = new int[n];
    int* temp = new int[n];
    int* temp2 = new int[n];

    do{
        cout<<"Prosze podac ilosc elementow do sortowania:"<<endl;
        cin>> n;

        double roznica=0,roznica2=0,roznica3=0,czas=0,czas2=0,czas3=0,srednia=0,srednia2=0,srednia3=0;  //zmienne do mierzenia czasu
        cout<<"Wybierz(od 1 do 4):"<<endl;
        cout<<"1.Wszystkie elementy tablicy losowe"<<endl;
        cout<<"2.Jakas czesc poczatkowych elementow jest juz posortowana"<<endl;
        cout<<"3.Wszystkie elementy posortowane w odwrotnej kolejnosci"<<endl;
        cout<<"4. Koniec"<<endl;
        cin>>wybor;

        switch(wybor){

        case 1:
        {

            for(int h=0;h<5;h++){
                   czas=0,czas2=0,czas3=0;
            for(int j=0;j<100;j++){
                for(int i=0;i<n;i++){
                    tab[i]=rand()%n;
                    temp[i]=tab[i];
            }

        start=clock(); //zapisanie czasu startu mierzenia
        SortowanieSzybkie(tab,0,n-1);
        koniec=clock();//zapisanie konca mierzenia

        roznica=(koniec-start)/(double)CLOCKS_PER_SEC;
        czas+=roznica;


        for(int i=0;i<n;i++){               //przepisanie z tablicy pomocniczej, żeby sortowania odbywały sie na tej samej tablicy
            tab[i]=temp[i];
        }

//Pomiar dla algorytmu sortowania przez kopcowanie

        start=clock();
        SortowaniePrzezKopcowanie(tab,n-1);
        koniec=clock();//zapisanie konca mierzenia

        roznica2=(koniec-start)/(double)CLOCKS_PER_SEC;
        czas2+=roznica2;

        for(int i=0;i<n;i++){               //przepisanie z tablicy pomocniczej, żeby sortowania odbywały sie na tej samej tablicy
            tab[i]=temp[i];
        }

//Pomiar dla sortowanie przez scalanie

        start=clock();
        SortowaniePrzezScalanie(tab,temp2,0,n-1);
        koniec=clock();//zapisanie konca mierzenia

        roznica3=(koniec-start)/(double)CLOCKS_PER_SEC;
        czas3+=roznica3;

    }
    //Sumowanie 5 czasow z sortowania stu tablic dla 3 algorytmow
    srednia+=czas;
    srednia2+=czas2;
    srednia3+=czas3;

}
    cout<<"Czas sortowania przez quicksort: "<<srednia/5<<endl;
    cout<<"Czas sortowania przez kopcowanie: "<<srednia2/5<<endl;
    cout<<"Czas sortowania przez scalanie: "<<srednia3/5<<endl;

        break;
    }
    case 2:
        {


        double procent;
        cout<<"Jaki procent elementow ma byc posortowany:"<<endl;
        cin>>procent;
        int k= n*(procent/100);
        int g=0;

        for(int h=0;h<5;h++){
                   czas=0,czas2=0,czas3=0;
        for(int j=0;j<100;j++){

            for(int i=0;i<k;i++){                   //wpisanie do tablicy czesci posortowanej

                tab[i]=g;
                g++;
            }
        g=0;
        for(int i=k;i<n;i++){                       //wpisanie do tablicy nieposortowanej czesci
            tab[i]=rand()%n;
        }
        for(int i=0;i<n;i++){                       //przepisanie do tablicy pomocniczej wartosci z glownej tablicy, na które wykonywane bedzie sortowanie
            temp[i]=tab[i];

        }

//Pomiar dla sortowania szybkiego

    start=clock(); //zapisanie czasu startu mierzenia
    SortowanieSzybkie(tab,0,n-1);
    koniec=clock();//zapisanie konca mierzenia

    roznica=(koniec-start)/(double)CLOCKS_PER_SEC;
    czas+=roznica;



        for(int i=0;i<n;i++){           //przepisanie z tablicy pomocniczej, żeby sortowania odbywały sie na tej samej tablicy
            tab[i]=temp[i];
            }

//Pomiar dla sortowania przez kopcowanie

            start=clock();
            SortowaniePrzezKopcowanie(tab,n-1);
            koniec=clock();//zapisanie konca mierzenia

        roznica2=(koniec-start)/(double)CLOCKS_PER_SEC;
        czas2+=roznica2;

        for(int i=0;i<n;i++){                       //przepisanie z tablicy pomocniczej, żeby sortowania odbywały sie na tej samej tablicy
            tab[i]=temp[i];
            }

//Pomiar dla sortowania przez scalanie

        start=clock();
        SortowaniePrzezScalanie(tab,temp2,0,n-1);
        koniec=clock();//zapisanie konca mierzenia

        roznica3=(koniec-start)/(double)CLOCKS_PER_SEC;
        czas3+=roznica3;

    }

    //Sumowanie 5 czasow z sortowania stu tablic dla 3 algorytmow
    srednia+=czas;
    srednia2+=czas2;
    srednia3+=czas3;

}
    cout<<"Czas sortowania przez quicksort: "<<srednia/5<<endl;
    cout<<"Czas sortowania przez kopcowanie: "<<srednia2/5<<endl;
    cout<<"Czas sortowania przez scalanie: "<<srednia3/5<<endl;



        break;
        }
    case 3:
    {

    int pomoc=n;
    for(int h=0;h<5;h++){
        czas=0,czas2=0,czas3=0;
        for(int j=0;j<100;j++){

            for(int i=0;i<n;i++){           //Wpisanie danych odwrotnie posortowanych
                tab[i]=pomoc;
                pomoc-=1;
                temp[i]=tab[i];
            }
            pomoc=n;

    //Pomiar dla algorytmu sortowania szybkiego

    start=clock(); //zapisanie czasu startu mierzenia
    SortowanieSzybkie(tab,0,n-1);
    koniec=clock();//zapisanie konca mierzenia

    roznica=(koniec-start)/(double)CLOCKS_PER_SEC;
    czas+=roznica;



        for(int i=0;i<n;i++){                   //przepisanie z tablicy pomocniczej, żeby sortowania odbywały sie na tej samej tablicy
            tab[i]=temp[i];
            }

//Pomiar dla algorytmu sortowania przez kopcowanie

            start=clock();
            SortowaniePrzezKopcowanie(tab,n-1);
            koniec=clock();//zapisanie konca mierzenia

        roznica2=(koniec-start)/(double)CLOCKS_PER_SEC;
        czas2+=roznica2;

        for(int i=0;i<n;i++){                   //przepisanie z tablicy pomocniczej, żeby sortowania odbywały sie na tej samej tablicy
            tab[i]=temp[i];
            }

//Pomiar dla algorytmu sortowania przez scalanie

        start=clock();
        SortowaniePrzezScalanie(tab,temp2,0,n-1);
        koniec=clock();//zapisanie konca mierzenia

        roznica3=(koniec-start)/(double)CLOCKS_PER_SEC;
        czas3+=roznica3;
        }
    //Sumowanie 5 czasow z sortowania stu tablic dla 3 algorytmow
    srednia+=czas;
    srednia2+=czas2;
    srednia3+=czas3;

}
    cout<<"Czas sortowania przez quicksort: "<<srednia/5<<endl;
    cout<<"Czas sortowania przez kopcowanie: "<<srednia2/5<<endl;
    cout<<"Czas sortowania przez scalanie: "<<srednia3/5<<endl;



        break;



    }
} //switch

}while(wybor!=4);

return 0;
}

