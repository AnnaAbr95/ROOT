
//reakcja pi- + p -> lambda0 + K0S
R__LOAD_LIBRARY (/opt/pluto6/builddir/libPluto.so)
int lambda0_discovery () 
{

    PReaction *my_reaction = new PReaction ("1.1", /* granica to 1.0*/

				"pi-", "p", 	      /* Substrates */
				"pi- K0S Lambda [p pi-]",      /*pominieto p jako tarcze bo wtedy problemy z ta linijka kodu, dziwny byl fakt, ze jesli pozostawiona zarowno pi- i p oraz dodano nawias ze sciezka rozpadu K0S to program mial potem problem z przypisaniem tego rozpadu, czy nalezy do lambdy czy do K0S mimo odpowiedniej kolejnosci nawiasow */
				"lambda0_discovery", 	      /* Output TTree filename */
				1, 0, 0, 0 );
    my_reaction->Print ();

    my_reaction->Loop (10000, 1);			/* No of events, status @ end */

    return 0;
}

