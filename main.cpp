#include <iostream>
#include <iomanip>
#include "math.h"
#include <thread>
#include "sstream"

using namespace std;

int main(int argc,char** argv)
{
    long double mn;
    long double niine=99980001;
    int preci=0;
    int choo_ser=0;
    cout<<"hello voyeristic behaviours have fun \n";
    cout<<"enter ur number , ur precision , ur nines pattern .Press 1 to change or 0 to leave it\n";
    cout<<"as it the default value is 99980001\n";
    mn=stold(argv[1]);
    preci=stoi(argv[2]);
    choo_ser=stoi(argv[3]);
    string mnb;
    mnb.clear();
    mnb+=to_string(mn);
    int nmlet=0;
    nmlet=mnb.size()-1;
   // cout<<mnb<<"\n";
   // cout<<"ur main number " << std::setprecision(preci) << mn << " with size of " << nmlet <<"\n";
    if (choo_ser==1){
       //cout<<"enter ur new nine pattern to use \n";
       //cin>>niine;
       //cout<<"ur new nine pattern will be ::== " << niine <<"\n";
       niine=stold(argv[4]);
    }
    stringstream mti;
    string inmn;
    inmn.clear();
    mti<<std::setprecision(preci)<<mn;
    inmn+=mti.str();
    int lin=0;
    lin=inmn.size();
    long double rst_d=0;
    rst_d=(long double)mn/(long double)niine;
    cout<<"\n";
    cout<<"of " << std::setprecision(preci) << mn << " / " << std::setprecision(preci) << niine << " ::== ";
    cout<< std::setprecision(preci) << rst_d <<"\n";
    cout<<"\n";
    long double fractpart,intpart;
    fractpart=modf(rst_d,&intpart);
    cout<<std::setprecision(preci) << intpart << " + " << std::setprecision(preci) << fractpart << " ::== " << std::setprecision(preci)<<rst_d <<"\n";
    cout<<"\n";
    long double sqtr=0;
    sqtr=sqrt(rst_d);
    cout<<"The main sqrt " << std::setprecision(preci) << sqrt(mn) <<" and ";
    cout<<"ur sqrt is " << std::setprecision(preci) << sqtr <<"\n";
    cout<<"\n";
    string slk;
    slk.clear();
    stringstream smk;
    smk<<std::setprecision(preci) << sqtr;
    slk+=smk.str();
    int let=0;
    let=slk.size()-1;
    cout<<"The String Representation is " << slk <<" with size " << let <<"\n";
    int xl=10;
    long double xmln=0;
    long double rxml=0;
    string lct;
    int st=0;int fnd=0;
    string mct;int tmc=0;
    for(int i=1;i<=let+1;i++)
    {
      xl=10;
      lct.clear();
      mct.clear();
      xl=pow(xl,i);
      xmln=sqtr*xl;
      rxml=xmln*xmln;
      fractpart=modf(rxml,&intpart);
      if(preci<i){preci=i;}
      stringstream xrm;
      xrm<<std::setprecision(preci)<<intpart;
      mct+=xrm.str();
      tmc=mct.size();
      //cout<<std::setprecision(preci) << intpart << " + " << fractpart << " ::== " << rxml <<"\n";
      if(intpart>=mn ){lct+=" ~= LOCATED ";
                      if(tmc>lin){lct+= " bigger "; lct+=to_string(tmc); lct+=" as main and " ; lct+=to_string(lin); lct+=" as this ";}
                      if(tmc<lin){lct+= " smaller "; lct+=to_string(tmc); lct+=" as main and " ; lct+=to_string(lin); lct+=" as this "; }
                      st=1;
                      }
      if(lin==tmc){lct+= " ==LOCATED "; lct+=" with size of "; lct+=to_string(tmc); lct+=" as main and " ; lct+=to_string(lin); lct+=" as this "; st=1;}
      cout<<"@i " <<std::setprecision(preci) << xl << " rst " << std::setprecision(preci) << xmln << " "  ;
      if(st==0){cout<<" -------> "<<std::setprecision(preci) << rxml << " " ;}
      if(st==1 && fnd==0){cout<<" -------> " << rxml <<" " << " vs " << mn << " " << lct <<"\n"; st=0; fnd=1;}
      cout<<"\n";
      if(st==1){break;}
    }
    return 0;
}
