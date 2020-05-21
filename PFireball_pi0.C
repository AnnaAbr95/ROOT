//reakcja z przykladu 7
//wg https://plutouser.github.io/v6.00/examples/thermal_rho.C.html
R__LOAD_LIBRARY (/opt/pluto6/builddir/libPluto.so)


int PFireball_pi0 ()
{ 

 
    PFixedDecay *pmodel = new PFixedDecay("pi0_gg", "pi0", -1);
    pmodel->Add("pi0, parent");
    pmodel->Add("g, daughter");
    pmodel->Add("g, daughter");
    makeDistributionManager()->Add(pmodel); //This enables the model

    makeDistributionManager()->Enable("pi0_gg");

    PFireball *source = new PFireball("pi0", 0.04, 0.015, 0.0, 1.0, 0.0, 0., 0., 0., 0.); //dane z przykladu 7
    source->setTrueThermal(kFALSE);

    PParticle *pi0 = new PParticle("pi0");
    PParticle *s1[] = {source, pi0};
    PChannel  *c1 = new PChannel(s1, 1, 1);

    PParticle *g1 = new PParticle("g");
    PParticle *g2 = new PParticle("g");
    PParticle *s2[] = {pi0, g1, g2};
    PChannel  *c2 = new PChannel(s2, 2, 1);

    PChannel  *cc[] = {c1, c2};
    PReaction *r = new PReaction(cc, "thermal_pi0", 2, 1, 1);
    r->Print();
    r->SetHGeant(0);   
    r->loop(10000);

return 0;
}

 
