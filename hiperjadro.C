//dziala czesiowo, problem z zdefiniowaniem nowej reakcji, zeby pozniejsie do niej odniesc w PReaction
//probowa z AddChannel, ale chyba za duzo produktow reakcji
//proba z AddReaction
//wg przykladu 9 ze skryptu po prostu zdefiniowanie PReaction, ale wtedy ROOT nie widzi zdefiniowanej kilka linijek wczesniej czastki z jakiegos powodu
// proba z zdefiniowaniem PReaction wg przykladu 1/2, ale wtedy nie mozna dac adresu do nowo wytworzonej czastki, bo problem z typem tej zmiennej
// reakcja 16O + p -> 16O_lambda + n + K0
// do wytworzenia hiperjadra
// zrodlo reakcji https://www.ifj.edu.pl/popularyzacja/mnn2012/prezentacje/odkrycie_hiperjader.pdf

R__LOAD_LIBRARY (/opt/pluto6/builddir/libPluto.so)


int hiperjadro () 
{
  double mN = 0.938, A = 16, mass_nucl = mN * 16, mass = 4 * mN;
  double mLambda=1.115; mass = mN * 15 + mLambda;

  //PDecayChannel *c;
  PStaticData *sd = makeStaticData() ;
  sd->AddParticle (-1, "16O", mass_nucl ); //dodanie do bazy nowej czastki 16O
  sd->AddParticle (-1, "16O_lambda", mass ); //dodanie do bazy nowej czastki 16O z lambda w jadrze, przyklad hiperjadra
  //sd->AddChannel(1.0, "16O", "p", "16O_lambda", "n","K+");
  //sd->AddReaction (-1, "16O + p -> 16O_lambda + n + K+", "16O,p", "16O_lambda,n,K+", 1.);


  PReaction *my_reaction = 
	new PReaction("2.1","16O","p", "16O_lambda n K+","16O",1,0,0,0);
    my_reaction->AddReaction("16O p 16O_lambda n K+");

   my_reaction->Print();
   my_reaction->Loop (10000, 1);
  //PReaction *R = new PReaction ("1.", "16O", "p", "16O p 16O_lambda n K+", "hiperjadro");
  //R->Print ();
  
  
   

return 0;
}
