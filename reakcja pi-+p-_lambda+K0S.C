// Na bazie przykladu 5 z skryptu o PLUTO
//Reakcja pi- + p -> lambda0 + K0S i dalesze rozpady produktow
//bazowanie na tablicach przy tworzeniu reakcji
R__LOAD_LIBRARY (/opt/pluto6/builddir/libPluto.so)

int lambda0_discovery_long () 
{

    PParticle p1 ("pi-", 1.5) , p2 ("p"); // do takiej energii rozpedzono pi- w eksperymencie, gdzie odkryto czastki lambda0
    PParticle cp = p1 + p2;
    PParticle p3 ("pi-"), p4 ("p"), p5 ("K0S"), p6 ("Lambda");

    PParticle* parttable_lambda0[] = { &cp , &p3 , &p5, &p6 }; //zalozenie, ze produktem jest tez pi-, ktora nie stracila calej swojej energii

    PChannel* lambda0_prod = new PChannel ( parttable_lambda0 , 3 );

                                                     

    PParticle p7 ("pi+") , p8 ("pi-");

    PParticle* parttable_pipi[] = { &p5, &p7 , &p8 }; // rozpad K0S

    PChannel* K0S_pipidecay = new PChannel ( parttable_pipi , 2 );
    
    
    PParticle p9 ("pi-") , p10 ("p");

    PParticle* parttable_pip[] = { &p6, &p9 , &p10 }; //rozpad lambda0

    PChannel* lambda0_pipdecay = new PChannel ( parttable_pip , 2 );
    
    

    //    Constructing the full reaction

    PChannel* table_of_channels[] = { lambda0_prod , K0S_pipidecay, lambda0_pipdecay  };

    PReaction* my_reaction = new PReaction 
               ( table_of_channels , "lambda0_discovery_long", 3 , 1 , 0 , 0 , 0 );

    my_reaction->Print ();

    my_reaction->Loop (10000, 1);			

    return 0;
}
