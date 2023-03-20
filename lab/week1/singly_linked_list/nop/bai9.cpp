void Polynomial::insertTerm(const Term& term) {
    // STUDENT ANSWER
    insertTerm(term.coeff, term.exp);
}

void Polynomial::insertTerm(double coeff, int exp) {
    // STUDENT ANSWER
    if (coeff == 0) return;
    int index = 0;
    for(auto it = terms->begin(); it != terms->end(); ++it){
        if((*it).exp == exp) {
            (*it).coeff += coeff;
            if((*it).coeff == 0) it.remove();
            return;
        } else if ((*it).exp < exp) {
            terms->add(index, Term(coeff,exp));
            return;
        }
        ++index;
    }
    if(index == terms->size()) terms->add(Term(coeff, exp));
}