#include "relatorio.hpp"

bool compara_candidatos(candidato c1, candidato c2){
    if(c1.get_votos() != c2.get_votos()) return c1.get_votos() > c2.get_votos();

    return c1.is_mais_velho(c2);
}

bool compara_partidos(partido p1, partido p2){
    if(p1.get_votos_totais() != p2.get_votos_totais()) return p1.get_votos_totais() > p2.get_votos_totais();

    return p2.get_numero() > p1.get_numero();
}

bool compara_partidos_posicao(partido p1, partido p2){
    return true;
}


relatorio::relatorio(map<int, candidato> candidatos, map<int, partido> partidos){
    this->partidos = partidos;

    for(const auto &[id, c] : candidatos) this->candidatos.push_back(c);
    
    sort(this->candidatos.begin(), this->candidatos.end(), compara_candidatos);

    for(const auto c : this->candidatos) if(c.get_eleito()) this->eleitos.push_back(c);
    
}

void relatorio::relatorio1() const{

    cout << "Número de vagas: " << this->eleitos.size() << endl;

}

void relatorio::relatorio2() const{
    
    cout << "Vereadores eleitos:" << endl;

    int n = 1;
    for(const auto c : this->candidatos) {
        if(!c.get_eleito()) continue;

        //c.imprime(n++);
    }

}

void relatorio::relatorio3() const{
    
    cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;

    int n = 1;
    for(const auto c : this->candidatos) {
        if(n > this->eleitos.size()) break;

        //c.imprime(n++);
    }

}

void relatorio::relatorio4() const{
    
    cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;

    int n = 0;
    for(const auto c : this->candidatos) {
        n++;
        if(n > this->eleitos.size()) break;

        if(c.get_eleito()) continue;

        //c.imprime(n);
    }

}

void relatorio::relatorio5() const{
    
    cout << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;

    int n = 0;
    for(const auto c : this->candidatos) {
        n++;
        if(n <= this->eleitos.size()) continue;
        
        if(!c.get_eleito()) continue;

        //c.imprime(n);
    }

}

void relatorio::relatorio6() const{
    
    cout << "Votação dos partidos e número de candidatos eleitos:" << endl;

    vector<partido> vector_partidos;
    for(const auto &[id, p] : this->partidos) vector_partidos.push_back(p);
    sort(vector_partidos.begin(), vector_partidos.end(), compara_partidos);

    int n = 1;
    for(const auto p : vector_partidos){

        cout << n++ << " - " << p.get_nome() << " - " << p.get_numero() << ", ";

        if(p.get_votos_totais() > 1) cout << p.get_votos_totais() << " votos ";
        else cout << p.get_votos_totais() << " voto ";

        if(p.get_votos_nominais() > 1) cout << "(" << p.get_votos_nominais() << " nominais e ";
        else cout << "(" << p.get_votos_nominais() << " nominal e ";

        cout << p.get_votos_legenda() << " de legenda), ";

        if(p.get_quantidade_eleitos() > 1) cout << p.get_quantidade_eleitos() << " candidatos eleitos" << endl;
        else cout << p.get_quantidade_eleitos() << " candidato eleito" << endl;

    }

}

void relatorio::relatorio7() const{
    
    cout << "Primeiro e último colocados de cada partido:" << endl;

    vector<partido> vector_partidos;
    for(const auto &[id, p] : this->partidos) if(p.get_candidatos().size() != 0) vector_partidos.push_back(p);
    sort(vector_partidos.begin(), vector_partidos.end(), compara_partidos_posicao);

    int n = 0;
    for(const auto p : vector_partidos){
        n++;
        if(p.get_votos_nominais() == 0) continue;

        cout << n << " - " << p.get_nome() << " - " << p.get_numero() << ", ";
        /*Candidato primeiro = p.getCandidadoPosicao(0);

        int size = p.getCandidatos().size() - 1;
        Candidato ultimo = p.getCandidadoPosicao(size);

        if(primeiro.getVotos() > 1) System.out.printf("%s (%d, %s votos) / ", primeiro.getNome(), primeiro.getNumero(), String.format("%,d", primeiro.getVotos()));
        else System.out.printf("%s (%d, %s voto) / ", primeiro.getNome(), primeiro.getNumero(), String.format("%,d", primeiro.getVotos()));


        if(ultimo.getVotos() > 1) System.out.printf("%s (%d, %s votos)\n", ultimo.getNome(), ultimo.getNumero(), String.format("%,d", ultimo.getVotos()));
        else System.out.printf("%s (%d, %s voto)\n", ultimo.getNome(), ultimo.getNumero(), String.format("%,d", ultimo.getVotos()));*/
    }

}