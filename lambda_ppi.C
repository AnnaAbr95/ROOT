R__LOAD_LIBRARY (/opt/pluto6/builddir/libPluto.so) /*obowiazuje dopiero od 6, makro dla preprocesora do podlaczenia biblioteki pluto */

int lambda_ppi () 
{
  PParticle lambda ("Lambda", 1.5 );    /* Source particle, Ekin [GeV], powstaje czastka, identyfikacja przez nazwy, domyslnie w gevach*/
    
  PReaction *my_reaction = new PReaction ( /*jakakolwiek zmiana to reakcja, ze moze sie rozpasc, ale niekoniecznie musi */
                &lambda ,            /* Source particle */
	        "pi- p",         /* Decay scheme of source particle, w jednej linijce 2 czastki */
        	"lambda_ppi",      /* Output TTree filename */

                                  /* further flags - optional */

                1, 		  /* 1 = save all particles, 0 = only tracked  */
		0,                /* Unused                                    */
                0,                /* 1 = generate production vertex, 0 = don't */
		0                 /* 1 = generate text output file , 0 = don't */
               );

    my_reaction->Print ();

    my_reaction->Loop (10000, 1);		    /* No of events, status @ end, zadziala tyle razy, 1 zeby wypisalo potem total events */

    return 0;
}

