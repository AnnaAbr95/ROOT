// rozpad lambda 0 -> n + pi0 
R__LOAD_LIBRARY (/opt/pluto6/builddir/libPluto.so)

int lambda_npi_pigg_klocki () 
{
    PParticle lambda ("Lambda", 1.0 );

    //   Decay   pi+ ---> mu+ , nu_mu

    PParticle n ("n") , pi0 ("pi0");

    PParticle* parttable[] = { &lambda, &n , &pi0 };

    PChannel* lambda_decay = new PChannel ( parttable , 2 );

           

    PChannel* table_of_channels[] = { lambda_decay };

    PReaction* my_reaction = new PReaction 
               ( table_of_channels , "lambda_npi_pigg_klocki", 1 , 1 , 0 , 0 , 1 );

    my_reaction->Print ();

    
    my_reaction->Loop (10000, 1);

    return 0;
}


