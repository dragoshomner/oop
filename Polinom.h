class Polinom{
    int grad;
    double *coeficienti;

    friend class Pereche;

public:
    Polinom();

    Polinom(int grad);

    Polinom(double *coeficientiConstruct, int grad);

    friend istream& operator >>(istream &in, Polinom &pol);

    friend ostream& operator <<(ostream &out, const Polinom &pol);

    double calcVal(double x, Polinom &pol);

    Polinom& operator=(const Polinom &pol);

    Polinom operator +(const Polinom &pol);

    Polinom operator -(const Polinom &pol);

    Polinom operator *(const Polinom &pol);

    Polinom operator /(const Polinom &pol);

    Polinom operator %(const Polinom &pol);

    double operator [](int poz);

    ~Polinom() {delete[] coeficienti;}
};

    Polinom::Polinom(){
        grad = 0;
        coeficienti = new double[0];
    }

    Polinom::Polinom(int grad){
        this->grad = grad;
        coeficienti = new double[grad + 1]();
    }

    Polinom::Polinom(double *coeficientiConstruct, int grad){
        this->grad = grad;
        coeficienti = new double[grad + 1];
        for(int i = 0 ; i <= grad ; i++){
            coeficienti[i] = coeficientiConstruct[i];
        }
    }

    istream& operator >>(istream &in, Polinom &pol){
        in>>pol.grad;
        delete[] pol.coeficienti;
        pol.coeficienti = new double[pol.grad + 1];
        for(int i = 0 ; i <= pol.grad ; i++){
            in>>pol.coeficienti[i];
        }
        return in;
    }

    ostream& operator <<(ostream &out, const Polinom &pol){
        for(int i = 0 ; i <= pol.grad ; i++){
            out<<pol.coeficienti[i]<<" ";
        }
        return out;
    }

    double Polinom::calcVal(double x, Polinom &pol){
        double valoare = 0 ;
        for(int i = 0 ; i <= pol.grad ; i++){
            valoare += pol.coeficienti[i] * pow(x, i);
        }
        return valoare;
    }

    Polinom& Polinom::operator=(const Polinom &pol){
        if(this == &pol)
            return *this;
        this->grad = pol.grad;
        delete[] coeficienti;
        coeficienti = new double[pol.grad];
        for(int i = 0 ; i <= this->grad ; i++){
            this->coeficienti[i] = pol.coeficienti[i];
        }
        return *this;
    }

    Polinom Polinom::operator+(const Polinom &pol){
        Polinom rez;
        rez.grad = max(pol.grad, this->grad);
        for(int i = 0 ; i <= rez.grad ; i++){
            rez.coeficienti[i] = this->coeficienti[i] + pol.coeficienti[i];
        }
        return rez;
    }

    Polinom Polinom::operator-(const Polinom &pol){
        Polinom rez;
        rez.grad = max(pol.grad, this->grad);
        for(int i = 0 ; i <= rez.grad ; i++){
            rez.coeficienti[i] = this->coeficienti[i] - pol.coeficienti[i];
        }
        return rez;
    }

    Polinom Polinom::operator*(const Polinom &pol){
        Polinom rez(pol.grad + this->grad);
        rez.grad = pol.grad + this->grad;
        for(int i = 0 ; i <= pol.grad ; i++){
            for(int j = 0 ; j <= this->grad ; j++){
                rez.coeficienti[i + j] += pol.coeficienti[i] * this->coeficienti[j];
            }
        }
        return rez;
    }

    Polinom Polinom::operator/(const Polinom &pol){
        if(pol.grad > this->grad){
            Polinom rez;
            return rez;
        }
        else{
            Polinom rez(this->grad - pol.grad);

            double *initPol = new double[this->grad + 1];
            double *difPol = new double[pol.grad + 1];

            for(int i = 0 ; i <= this->grad ; i++){
                initPol[i] = this->coeficienti[i];
            }

            for(int pas = 0 ; pas <= this->grad - pol.grad ; pas++){
                rez.coeficienti[rez.grad - pas] = initPol[this->grad - pas] / pol.coeficienti[pol.grad];
                for(int i = 0 ; i <= pol.grad ; i++){
                    difPol[i] = (initPol[this->grad - pas] / pol.coeficienti[pol.grad])* pol.coeficienti[i];
                }

                int j = this->grad - pas;
                for(int i = pol.grad ; i >= 0 ; i--){
                    initPol[j] -= difPol[i];
                    j--;
                }
            }

            return rez;
        }
    }

    Polinom Polinom::operator%(const Polinom &pol){
        Polinom restPol = *this - (*this / pol) * pol;
        for(int i = restPol.grad ; !restPol.coeficienti[i] && i ; i--)
            restPol.grad --;
        return restPol;
    }

    double Polinom::operator[](int poz){
        return coeficienti[poz];
    }

