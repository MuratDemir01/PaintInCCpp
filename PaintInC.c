
#include <allegro.h>
#include <stdio.h>
#include <math.h>

void Yarat();
void Arayuz();
void Cizgiler();
void Renkler();
void Araclar();
void FareVeriAl();
void FareArac();
void FareRenk();
void FareDenetle();

typedef struct adimlar{
    BITMAP* an;
    struct adimlar *sonraki,*onceki;
}adimlar;


BITMAP *bmp,*anonce,*ana,*sayfa,*ekler;
int arac,birincilrenk,ikincilrenk,arkarenk,boyut,sayim;

struct adimlar *adim,*yeni,*ilk,*son,*artanlar,*artan;


int main(){
    Yarat();
    arac=1;
    boyut=4;
    ana=create_bitmap(1000,600);
    sayfa=create_bitmap(950,560);
    anonce=create_bitmap(1000,600);

    adim = (adimlar* ) malloc(sizeof(adimlar));
    ilk=adim;
    son=adim;

    bmp=ana;



    ilk->onceki=NULL;
    ilk->sonraki=NULL;

    show_mouse(screen);
    Arayuz();


    adim->an=create_bitmap(950,560);
    blit(bmp,adim->an,50,40,0,0,950,560);
    artanlar=adim;


    while (!key[KEY_ESC]){
        acquire_screen();
        blit(bmp, screen, 0, 0, 0, 0, 1000, 600);
        release_screen();

        if((mouse_x>51)&&(mouse_y>41)&&(mouse_y<600))
            FareVeriAl();
        else if(mouse_x<50 && mouse_y>41 && mouse_y<600)
            FareArac();
        else if(mouse_x>601 && mouse_x<855  && mouse_y<40 )
            FareRenk();
        else if(mouse_y<40)
        		FareDenetle();


    }


    clear_keybuf();
}
END_OF_MAIN();



void Yarat(){
    int derinlik, actimi;
    allegro_init();
    derinlik = desktop_color_depth();
    if (derinlik == 0)
        derinlik = 32;
    set_color_depth(derinlik);
    actimi = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1000, 600, 0, 0);
    if (actimi != 0)
    {
        allegro_message(allegro_error);
        exit(-1);
    }

    install_timer();
    install_keyboard();
    install_mouse();
    set_window_title("Created by Atakan A. Murat D. <.<");
}

void Arayuz(){
    clear_to_color(bmp,makecol(75,150,150));//Arkada görünmeyen renk atamakta
    birincilrenk=makecol(0,0,0);
    ikincilrenk=makecol(255,255,255);
    Araclar();
    Cizgiler();
    Renkler();
    rectfill(bmp,51,41,1000,600,ikincilrenk);//Her tarafy ikincil yani beyaz renk yapmakta
}

void Cizgiler(){
    /*Ana çizgiler*/
    hline(bmp,0,40,1000,makecol(0,0,0));//Yatay çizgi
    vline(bmp,50,40,600,makecol(0,0,0));//Dikey çizgiler
    /*Ara çizgiler*/
    hline(bmp,0,80,50,makecol(0,0,0));
    hline(bmp,0,120,50,makecol(0,0,0));
    hline(bmp,0,160,50,makecol(0,0,0));
    hline(bmp,0,200,50,makecol(0,0,0));
    hline(bmp,0,240,50,makecol(0,0,0));
    hline(bmp,0,280,50,makecol(0,0,0));
    hline(bmp,0,320,50,makecol(0,0,0));
    hline(bmp,0,360,50,makecol(0,0,0));
    hline(bmp,0,400,50,makecol(0,0,0));
    hline(bmp,0,440,50,makecol(0,0,0));
    hline(bmp,0,480,50,makecol(0,0,0));
    hline(bmp,0,520,50,makecol(0,0,0));

}

void Renkler(){
    int i=0,say=0;//açmak için her rengi 1 arttir.
    int r = getr(birincilrenk);
     int g = getg(birincilrenk);
     int b = getb(birincilrenk);

    for(i=0;i<255;i++){
        rectfill(bmp,600+i,0,600+i+1,5,makecol(i,g,b));//makecol(r,g,b)
    }
    for(i=0;i<255;i++){
        rectfill(bmp,600+i,6,600+i+1,10,makecol(r,i,b));//makecol(r,g,b)
    }
    for(i=0;i<255;i++){
        rectfill(bmp,600+i,10,600+i+1,15,makecol(r,g,i));//makecol(r,g,b)
    }


    for(i=0;i<255;i++){
        rectfill(bmp,600+i,16,600+i+1,20,makecol(i,i,i));//makecol(r,g,b)
    }

    rectfill(bmp,600,22,615,37,makecol(255,0,0));
    rectfill(bmp,615,22,630,37,makecol(0,255,0));
    rectfill(bmp,630,22,645,37,makecol(0,0,255));
    rectfill(bmp,645,22,660,37,makecol(0,0,1));
    rectfill(bmp,660,22,675,37,makecol(255,255,255));
    rectfill(bmp,675,22,690,37,makecol(255,255,0));
    rectfill(bmp,690,22,705,37,makecol(128,0,0));
    rectfill(bmp,690,22,705,37,makecol(255,128,128));
    rectfill(bmp,705,22,720,37,makecol(255,128,0));
    rectfill(bmp,720,22,735,37,makecol(128,64,0));
    rectfill(bmp,735,22,750,37,makecol(128,128,0));
    rectfill(bmp,750,22,765,37,makecol(128,0,255));
    rectfill(bmp,765,22,780,37,makecol(0,128,0));
    rectfill(bmp,780,22,795,37,makecol(0,64,0));
    rectfill(bmp,795,22,810,37,makecol(0,128,128));
    rectfill(bmp,810,22,825,37,makecol(0,255,255));
    rectfill(bmp,825,22,840,37,makecol(0,0,128));
    rectfill(bmp,840,22,855,37,makecol(255,0,255));


    rectfill(bmp,555,5,575,25,ikincilrenk);
    rectfill(bmp,565,15,585,35,birincilrenk);
}

void Araclar(){

    rectfill(bmp, 0, 0, 1000, 40,makecol(130,225,255));
    rectfill(bmp, 0, 0, 50, 600,makecol(130,225,255));

    textprintf_centre_ex(bmp, font,38, 23, makecol(0, 0, 0),-1,"%d",arac);

    textprintf_centre_ex(bmp, font,220, 30, makecol(0, 0, 0),-1,"%d",sayim);

    /*Yandaki araçlarýn görselleri*/
    ekler=load_bitmap("pencil.bmp",NULL);
    blit(ekler,bmp, 0, 0, 0, 41,50,39);
    ekler=load_bitmap("eraser.bmp",NULL);
    blit(ekler,bmp, 0, 0, 0, 281,50,39);
    ekler=load_bitmap("triangle.bmp",NULL);
    blit(ekler,bmp, 0, 0, 0, 321,50,39);
    ekler=load_bitmap("trianglefill.bmp",NULL);
    blit(ekler,bmp, 0, 0, 0, 361,50,39);
    ekler=load_bitmap("floodfill.bmp",NULL);
    blit(ekler,bmp, 0, 0, 0, 441,50,39);

    /*Üsteki dosya iþlemlerin görselleri*/
    ekler=load_bitmap("new.bmp",NULL);
    blit(ekler,bmp, 0, 0, 50, 0,50,39);
    ekler=load_bitmap("save.bmp",NULL);
    blit(ekler,bmp, 0, 0, 100, 0,50,39);
    ekler=load_bitmap("load.bmp",NULL);
    blit(ekler,bmp, 0, 0, 150, 0,50,39);
    ekler=load_bitmap("undoredo.bmp",NULL);
    blit(ekler,bmp, 0, 0, 200, 0,100,39);
    ekler=load_bitmap("exit.bmp",NULL);
    blit(ekler,bmp, 0, 0, 950, 0,50,39);

    textprintf_centre_ex(bmp, font,250, 30, makecol(0, 0, 0),-1,"%d",sayim);


    line(bmp,5,90,35,110,makecol(0,0,0));//line tool selection





    rect(bmp,5,130,35,150,makecol(0,0,0));//rect tool selection

    rectfill(bmp,5,170,35,190,makecol(0,0,0));//rectfill tool selection

    circle(bmp,20,220,15,makecol(0,0,0));//circle tool selection

    circlefill(bmp,20,260,15,makecol(0,0,0));//circle tool selection



    textprintf_centre_ex(bmp, font, 25, 410, makecol(20, 24, 100),-1,"-Boyut+");

    textprintf_centre_ex(bmp, font, 25, 420, makecol(20, 24, 100),-1,"%d",boyut);
}



void FareVeriAl(){
    int ilkx,ilky,dairex,dairey;

    if(mouse_b==1){
            ilkx=mouse_x;
            ilky=mouse_y;
            int cap;
        if(arac==1){
            blit(bmp,anonce,0, 0, 0, 0, 1000, 600);
            while(mouse_b & 1){
                ilkx=mouse_x;
                ilky=mouse_y;
                acquire_screen();
                blit(anonce,screen,0, 0, 0, 0, 1000, 600);
                release_screen();
                blit(bmp,anonce,0, 0, 0, 0, 1000, 600);

                 rectfill(bmp,ilkx-boyut/2,ilky-boyut/2,mouse_x+boyut/2,mouse_y+boyut/2,birincilrenk);

            }
            rectfill(bmp,mouse_x-boyut/2,mouse_y-boyut/2,mouse_x+boyut/2,mouse_y+boyut/2,birincilrenk);
    }
    		else if(arac==7){
            blit(bmp,anonce,0, 0, 0, 0, 1000, 600);
            while(mouse_b & 1){
                ilkx=mouse_x;
                ilky=mouse_y;
                acquire_screen();
                blit(anonce,screen,0, 0, 0, 0, 1000, 600);
                release_screen();
                blit(bmp,anonce,0, 0, 0, 0, 1000, 600);

                 rectfill(bmp,ilkx-boyut/2,ilky-boyut/2,mouse_x+boyut/2,mouse_y+boyut/2,ikincilrenk);

            }
            rectfill(bmp,mouse_x-boyut/2,mouse_y-boyut/2,mouse_x+boyut/2,mouse_y+boyut/2,ikincilrenk);

    		}
            else if(arac==10){
                    blit(bmp,anonce,0, 0, 0, 0, 1000, 600);
                floodfill(bmp,mouse_x , mouse_y, birincilrenk);
            while(mouse_b & 1){
                ilkx=mouse_x;
                ilky=mouse_y;
                acquire_screen();
                blit(anonce,screen,0, 0, 0, 0, 1000, 600);
                release_screen();
                blit(bmp,anonce,0, 0, 0, 0, 1000, 600);

                 floodfill(bmp,mouse_x , mouse_y, birincilrenk);

            }
            floodfill(bmp,mouse_x , mouse_y, birincilrenk);
            }
        else {


            blit(bmp,anonce,0, 0, 0, 0, 1000, 600);
            while(mouse_b & 1){
                acquire_screen();
                blit(anonce,screen,0, 0, 0, 0, 1000, 600);
                release_screen();
                blit(bmp,anonce,0, 0, 0, 0, 1000, 600);
                if(arac==2)
                line(anonce,ilkx,ilky,mouse_x,mouse_y,birincilrenk);


            else if(arac==3)
                rect(anonce,ilkx,ilky,mouse_x,mouse_y,birincilrenk);
            else if(arac==4)
                rectfill(anonce,ilkx,ilky,mouse_x,mouse_y,birincilrenk);
            else if(arac==5){
                cap=sqrt(((mouse_x-ilkx)*(mouse_x-ilkx))+((mouse_y-ilky)*(mouse_y-ilky)))/2;
                dairex=ilkx+(mouse_x-ilkx)/2;
                dairey=ilky+(mouse_y-ilky)/2;
                circle(anonce,dairex,dairey,cap,birincilrenk);

            }
            else if(arac==6){
                cap=sqrt(((mouse_x-ilkx)*(mouse_x-ilkx))+((mouse_y-ilky)*(mouse_y-ilky)))/2;
                dairex=ilkx+(mouse_x-ilkx)/2;
                dairey=ilky+(mouse_y-ilky)/2;
                circlefill(anonce,dairex,dairey,cap,birincilrenk);
            }
            else if(arac==8){
                line(anonce,ilkx,ilky,2*ilkx-mouse_x,mouse_y,birincilrenk);
                line(anonce,2*ilkx-mouse_x,mouse_y,mouse_x,mouse_y,birincilrenk);
                line(anonce,mouse_x,mouse_y,ilkx,ilky,birincilrenk);
            }
            else if(arac==9){
                triangle(anonce,ilkx,ilky,2*ilkx-mouse_x,mouse_y,mouse_x,mouse_y,birincilrenk);
            }

            }

            acquire_screen();
                blit(bmp, screen, 0, 0, 0, 0, 1000, 600);
                release_screen();

            if(arac==2)
                line(bmp,ilkx,ilky,mouse_x,mouse_y,birincilrenk);
            else if(arac==3)
                rect(bmp,ilkx,ilky,mouse_x,mouse_y,birincilrenk);
            else if(arac==4)
                rectfill(bmp,ilkx,ilky,mouse_x,mouse_y,birincilrenk);
            else if(arac==5){
             		cap=sqrt(((mouse_x-ilkx)*(mouse_x-ilkx))+((mouse_y-ilky)*(mouse_y-ilky)))/2;
                ilkx=ilkx+(mouse_x-ilkx)/2;
                ilky=ilky+(mouse_y-ilky)/2;
                circle(bmp,ilkx,ilky,cap,birincilrenk);

            }
            else if(arac==6){
                cap=sqrt(((mouse_x-ilkx)*(mouse_x-ilkx))+((mouse_y-ilky)*(mouse_y-ilky)))/2;
                ilkx=ilkx+(mouse_x-ilkx)/2;
                ilky=ilky+(mouse_y-ilky)/2;
                circlefill(bmp,ilkx,ilky,cap,birincilrenk);
            }
            else if(arac==8){
                line(bmp,ilkx,ilky,2*ilkx-mouse_x,mouse_y,birincilrenk);
                line(bmp,2*ilkx-mouse_x,mouse_y,mouse_x,mouse_y,birincilrenk);
                line(bmp,mouse_x,mouse_y,ilkx,ilky,birincilrenk);
                }
            else if(arac==9){
                int x1=(mouse_x-ilkx)/2+ilkx;
                triangle(bmp,ilkx,ilky,2*ilkx-mouse_x,mouse_y,mouse_x,mouse_y,birincilrenk);
            }

        }



        adim = (adimlar* ) malloc(sizeof(adimlar));
        son->sonraki=adim;
        adim->onceki=son;
        son=adim;

        son->sonraki=NULL;
        sayim++;
        adim->an=create_bitmap(950,560);
        blit(bmp,adim->an,50,40,0,0,950,560);

    }

    Araclar();
    Cizgiler();
    Renkler();

}

void FareRenk(){
    if(getpixel(screen,mouse_x,mouse_y)!=arkarenk)
        if(mouse_b==1)
            birincilrenk=getpixel(screen,mouse_x,mouse_y);
        else if(mouse_b==2)
            ikincilrenk=getpixel(screen,mouse_x,mouse_y);
    Araclar();
    Cizgiler();
    Renkler();

}

void FareArac(){
       if(mouse_b==1)
    {
        if(mouse_y>40 && mouse_y<80)
            arac=1;
        else if(mouse_y<120 && mouse_y>80)
            arac=2;
        else if(mouse_y<160 && mouse_y>120)
            arac=3;
        else if(mouse_y<200 && mouse_y>160)
            arac=4;
        else if(mouse_y<240 && mouse_y>200)
            arac=5;
        else if(mouse_y<280 && mouse_y>240)
            arac=6;
        else if(mouse_y<320 && mouse_y>280)
            arac=7;
        else if(mouse_y<360 && mouse_y>320)
            arac=8;
        else if(mouse_y<400 && mouse_y>360)
            arac=9;
        else if(mouse_y<440 && mouse_y>400){
            if(mouse_x<25){
              if(boyut>1)
                boyut--;
                rest(15);
            }
            else if(mouse_x<50){
              boyut++;
                rest(15);
            }
        }
        else if(mouse_y<480 && mouse_y>440)
            arac=10;
    }
    Araclar();
    Cizgiler();
    Renkler();

}

void FareDenetle(){
    if(mouse_b==1){
        if(mouse_x>50 && mouse_x<100)
            rectfill(bmp,51,41,1000,600,makecol(255,255,255));
        else if(mouse_x>100 && mouse_x<150){
            blit(bmp,sayfa,50,40,0,0,950,560);
            save_bitmap("Kaydedilen.bmp",sayfa,NULL);
      	}else if(mouse_x>150 && mouse_x<200){
      	    if(load_bitmap("Kaydedilen.bmp",NULL)!=NULL){
                sayfa=load_bitmap("Kaydedilen.bmp",NULL);
                blit(sayfa,bmp, 0, 0, 50, 40,950,560);
      	    }
        }else if(mouse_x>200 && mouse_x<250){
            while(mouse_b&1){}
                if(adim->onceki!=NULL){
                    artanlar=adim;
                    adim=adim->onceki;
                    son=adim;
                    blit(adim->an,bmp, 0, 0, 50, 40,950,560);
                    sayim--;
		    }
		}else if(mouse_x>250 && mouse_x<300){
		    while(mouse_b&1){}
		    if(adim->sonraki!=NULL){
                adim=adim->sonraki;
                blit(adim->an,bmp, 0, 0, 50, 40,950,560);
                sayim++;
		    }
		}
		else if(mouse_x>950 && mouse_x<1000)
            exit(1);

    }


    Araclar();
    Cizgiler();
    Renkler();


}
