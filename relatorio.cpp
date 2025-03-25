#include "relatorio.hpp"
#include <iomanip>

void candidato_imprime(candidato c, int n){
    cout << n << " - ";

    if(c.get_partido()->is_federacao()) cout << "*";
    cout << c.get_nome() << " (" << c.get_partido()->get_nome() << ", " << c.get_votos() << " votos)" << endl;
}


relatorio::relatorio(map<int, candidato> candidatos, map<int, partido> partidos, const calendario &data_eleicao): data_eleicao(data_eleicao) {  
    this->partidos = partidos;

    for(const auto &[id, c] : candidatos) this->candidatos.push_back(c);
    
    sort(this->candidatos.begin(), this->candidatos.end(), compara_candidatos);

    for(const auto &c : this->candidatos) if(c.get_eleito()) this->eleitos.push_back(c);
    
}

void relatorio::relatorio1() const{

    cout << "Número de vagas: " << this->eleitos.size() << endl;

}

void relatorio::relatorio2() const{
    
    cout << "Vereadores eleitos:" << endl;

    int n = 1;
    for(const auto &c : this->candidatos) {
        if(!c.get_eleito()) continue;

        candidato_imprime(c, n++);
    }

}

void relatorio::relatorio3() const{
    
    cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;

    long unsigned int n = 1;
    for(const auto &c : this->candidatos) {
        if(n > this->eleitos.size()) break;

        candidato_imprime(c, n++);
    }

}

void relatorio::relatorio4() const{
    
    cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;

    long unsigned int n = 0;
    for(const auto &c : this->candidatos) {
        n++;
        if(n > this->eleitos.size()) break;

        if(c.get_eleito()) continue;

        candidato_imprime(c, n);
    }

}

void relatorio::relatorio5() const{
    
    cout << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;

    long unsigned int n = 0;
    for(const auto &c : this->candidatos) {
        n++;
        if(n <= this->eleitos.size()) continue;
        
        if(!c.get_eleito()) continue;

        candidato_imprime(c, n);
    }

}

void relatorio::relatorio6() const{
    
    cout << "Votação dos partidos e número de candidatos eleitos:" << endl;

    vector<partido> vector_partidos;
    for(const auto &[id, p] : this->partidos) vector_partidos.push_back(p);
    sort(vector_partidos.begin(), vector_partidos.end(), compara_partidos);

    int n = 1;
    for(const auto &p : vector_partidos){

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
    for(auto [id, p] : this->partidos){
        p.sort_candidatos();
        if(p.get_candidatos().size() != 0) vector_partidos.push_back(p);
    }

    sort(vector_partidos.begin(), vector_partidos.end(), compara_partidos_posicao);

    int n = 0;
    for(auto p : vector_partidos){
        n++;
        if(p.get_votos_nominais() == 0) continue;

        cout << n << " - " << p.get_nome() << " - " << p.get_numero() << ", ";
        candidato * primeiro = p.get_candidato_posicao(0);

        int size = p.get_candidatos().size() - 1;
        candidato * ultimo = p.get_candidato_posicao(size);

        string p_num = to_string(primeiro->get_numero());
        p_num.erase(std::remove(p_num.begin(), p_num.end(), '.'), p_num.end());

        string u_num = to_string(ultimo->get_numero());
        u_num.erase(std::remove(u_num.begin(), u_num.end(), '.'), u_num.end());

        if(primeiro->get_votos() > 1) cout << primeiro->get_nome() << " (" << p_num << ", " << primeiro->get_votos() << " votos) / ";
        else cout << primeiro->get_nome() << " (" << primeiro->get_numero() << ", " << p_num << " voto) / ";


        if(ultimo->get_votos() > 1) cout << ultimo->get_nome() << " (" << u_num << ", " << ultimo->get_votos() << " votos)" << endl;
        else cout << ultimo->get_nome() << " (" << u_num << ", " << ultimo->get_votos() << " voto)" << endl;
    }

}

void relatorio::relatorio8() const{
    int b30 = 0, b30_40 = 0, b40_50 = 0, b50_60 = 0, b60 = 0;

    int idade = 0;
    for(const auto &c : this->eleitos){
        idade = c.get_idade(this->data_eleicao);

        if(idade < 30) b30++;
        else if(idade < 40) b30_40++;
        else if(idade < 50) b40_50++;
        else if(idade < 60) b50_60++;
        else b60++;
    }

    float total = this->eleitos.size();

    if(total == 0) {
        cout << "0 eleitos registrados" << endl;
        return;
    }

    cout << "Eleitos, por faixa etária (na data da eleição):" << endl;

    cout << "      Idade < 30: " << b30 << " (" << (b30 * 100) / total << "%)" << endl;
    cout << "30 <= Idade < 40: " << b30_40 << " (" << (b30_40 * 100) / total << "%)" << endl;
    cout << "40 <= Idade < 50: " << b40_50 << " (" << (b40_50 * 100) / total << "%)" << endl;
    cout << "50 <= Idade < 60: " << b50_60 << " (" << (b50_60 * 100) / total << "%)" << endl;
    cout << "60 <= Idade     : " << b60 << " (" << (b60 * 100) / total << "%)" << endl;
}

void relatorio::relatorio9() const{
    int m = 0, f = 0;

    for(const auto &c : this->eleitos){
        if(c.get_genero() == MASCULINO) m++;
        if(c.get_genero() == FEMININO) f++;
    }

    float total = this->eleitos.size();

    if(total == 0) {
        cout << "0 eleitos registrados" << endl;
        return;
    }

    cout << "Eleitos, por gênero:" << endl;

    cout << "Feminino: " << f << " (" << (f * 100) / total << "%)" << endl;
    cout << "Masculino: " << m << " (" << (m * 100) / total << "%)" << endl;
}

void relatorio::relatorio10() const{
    int total = 0, legenda = 0, nominal = 0;

    for(const auto &[id, p] : this->partidos){
        total += p.get_votos_totais();
        legenda += p.get_votos_legenda();
        nominal += p.get_votos_nominais();
    }

    if(total == 0) {
        cout << "0 eleitos registrados" << endl;
        return;
    }

    cout << "Total de votos válidos: " << total << endl;
    cout << "Total de votos nominais: " << nominal << " (" << (float) (nominal * 100) / total << "%)" << endl;
    cout << "Total de votos de legenda: " << legenda << " (" << (float) (legenda * 100) / total << "%)" << endl;
}

void relatorio::gera_relatorio() const{
    cout << setprecision(2) << fixed;

    this->relatorio1();
    cout << endl;
    this->relatorio2();
    cout << endl;
    this->relatorio3();
    cout << endl;
    this->relatorio4();
    cout << endl;
    this->relatorio5();
    cout << endl;
    this->relatorio6();
    cout << endl;
    this->relatorio7();
    cout << endl;
    this->relatorio8();
    cout << endl;
    this->relatorio9();
    cout << endl;
    this->relatorio10();
}