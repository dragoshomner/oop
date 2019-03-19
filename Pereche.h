class Pereche{
    double x;
    Polinom pol;

public:
    friend istream& operator >>(istream &in, Pereche &per);

    friend ostream& operator <<(ostream &out, Pereche &per);

    bool verificaRadacina(Pereche &per);
};

    istream& operator>>(istream &in, Pereche &per){
        in>>per.x;
        in>>per.pol;
        return in;
    }

    ostream& operator<<(ostream &out, Pereche &per){
        out<<per.x<<'\n';
        out<<per.pol;
        return out;
    }

    bool Pereche::verificaRadacina(Pereche &per){
        if(per.pol.calcVal(per.x, per.pol))
            return false;
        return true;
    }
