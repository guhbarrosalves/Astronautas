#include <iostream>
#include <string>
#include <vector>

using namespace std;    

class Astronauta {
private:
    string cpf;
    string nome;
    int idade;
    bool vivo;
    bool disponivel;
public:
    Astronauta(string c, string n, int i){
        cpf = c;
        nome = n;
        idade = i;
        vivo = 1;
        disponivel = 1;
    }

    string getCpf(){ return cpf;}
    string getNome(){ return nome;}
    int getIdade(){ return idade;}
    bool estaVivo(){ return vivo;}
    bool estaDisponivel(){ return disponivel;}
    void embarcar(){
        disponivel = 0;
    }
    void desembarcar(){  // volta a ficar disponivel, se estiver vivo
        if(vivo)
            disponivel = 1;
    }
    void morrer(){  // fica morto e indisponivel
        vivo = 0;
        disponivel = 0;
    }        
};

class Voo {
private:
    int codigo;
    string estado;
    vector<string> cpfs;
public:
    Voo(int cod){
        codigo = cod;
        estado = "planejado";
        // vetores já começam zerados.
    }

    int getCodigo(){return codigo;}
    string getEstado(){return estado;}
    int getQuantidadeAstronautas(){return cpfs.size();}
    string getCpf(int posicao){ return cpfs[posicao];}
    bool temAstronauta(string cpf){
        for(size_t i=0; i<cpfs.size(); i++){
            if(cpfs[i] == cpf)
                return 1;
        }
        return 0;
    }
    void adicionarAstronauta(string cpf){ cpfs.push_back(cpf); }
    bool removerAstronauta(string cpf){
        for(size_t i=0; i<cpfs.size(); i++){
            if(cpfs[i] == cpf){
                cpfs.erase(cpfs.begin() + i);
                return 1;
            }
        }
        return 0;
    } // false se o CPF nao estava no voo
    void lancar(){
        estado = "em curso";
    }
    void explodir(){
        estado = "finalizado com explosao";
    }
    void finalizar(){
        estado = "finalizado com sucesso";
    }
};

class Agencia {
private:
    vector<Astronauta> astronautas;
    vector<Voo> voos;
    int buscarAstronauta(string cpf){ // posicao no vector, ou -1
        for(size_t i=0; i<astronautas.size(); i++){
            if(astronautas[i].getCpf() == cpf){
                return i;
            }
        }
        return -1;
    }     
    int buscarVoo(int codigo){
        for(size_t i=0; i<voos.size(); i++){
            if(voos[i].getCodigo() == codigo){
                return i;
            }
        }
        return -1;
    }            // posicao no vector, ou -1
public:
    void cadastrarAstronauta(string cpf, string nome, int idade){
        if(buscarAstronauta(cpf) != -1){
            cout << "ERRO: astronauta com CPF " << cpf << " ja cadastrado" << endl;
            return;
        }
            astronautas.push_back(Astronauta(cpf, nome, idade));
            cout << "OK: astronauta " << cpf << " cadastrado" << endl;
        
    }
    void cadastrarVoo(int codigo){
        if(buscarVoo(codigo) != -1){
            cout << "ERRO: voo " << codigo << " ja cadastrado" << endl;
            return;
        }
            voos.push_back(Voo(codigo));
            cout << "OK: voo " << codigo << " cadastrado" << endl;

    }

    void adicionarAstronauta(string cpf, int codigo){
        int posAstronauta = buscarAstronauta(cpf);
        int posVoo = buscarVoo(codigo);
        if(posAstronauta == -1){
            cout << "ERRO: astronauta " << cpf << " nao cadastrado\n";
            return;
        }
        else{
            if(astronautas[posAstronauta].estaVivo() == 0){
                cout << "ERRO: astronauta " << cpf << " esta morto\n";
                return;
            }
        }
        if(buscarVoo(codigo) == -1){
            cout << "ERRO: voo " << codigo << " nao cadastrado\n";
            return;
        }
        else{
            if(voos[posVoo].getEstado() != "planejado"){
                cout << "ERRO: voo " << codigo << " nao esta planejado\n";
                return;
            }
            if(voos[posVoo].temAstronauta(cpf)){
                cout << "ERRO: astronauta " << cpf << " ja esta no voo " << codigo << "\n";
                return; 
                }
        }
        

        voos[posVoo].adicionarAstronauta(cpf);
        cout << "OK: astronauta " << cpf << " adicionado ao voo " << codigo << "\n";


    }
    void removerAstronauta(string cpf, int codigo){
        int posVoo = buscarVoo(codigo);
        if(buscarAstronauta(cpf) == -1){
            cout << "ERRO: astronauta " << cpf << " nao cadastrado\n";
            return;
        }
        if(buscarVoo(codigo) == -1){
            cout << "ERRO: voo " << codigo << " nao cadastrado\n";
            return;
        }
        else{
            if(voos[posVoo].getEstado() != "planejado"){
                cout << "ERRO: voo " << codigo << " nao esta planejado\n";
                return;
            }
            if(!voos[posVoo].temAstronauta(cpf)){
                cout << "ERRO: astronauta " << cpf << " nao esta no voo " << codigo << "\n";
                return; 
                }
        }
        

        voos[posVoo].removerAstronauta(cpf);
        cout << "OK: astronauta " << cpf << " removido do voo " << codigo << "\n";

    }
    void lancarVoo(int codigo){
        int posVoo = buscarVoo(codigo);
        if(posVoo == -1){
            cout << "ERRO: voo " << codigo << " nao cadastrado\n";
            return;
        }
        if(voos[posVoo].getEstado() != "planejado"){
            cout << "ERRO: voo " << codigo << " nao esta planejado\n";
            return;
        }
        if(voos[posVoo].getQuantidadeAstronautas() == 0){
            cout << "ERRO: voo " << codigo << " nao possui astronautas\n";
            return;
        }

        for(size_t i=0; i<voos[posVoo].getQuantidadeAstronautas(); i++){
            string cpf = voos[posVoo].getCpf(i);
            if(!astronautas[buscarAstronauta(cpf)].estaVivo()){
                cout << "ERRO: astronauta " << astronautas[buscarAstronauta(cpf)].getCpf() << " esta morto\n";
                return;
            }
            if(!astronautas[buscarAstronauta(cpf)].estaDisponivel()){
                cout << "ERRO: astronauta " << astronautas[buscarAstronauta(cpf)].getCpf() << " esta indisponivel\n";
                return;
            }

        }
        for(size_t j=0; j<voos[posVoo].getQuantidadeAstronautas(); j++){
            string cpf = voos[posVoo].getCpf(j);
            astronautas[buscarAstronauta(cpf)].embarcar();
        }
        voos[posVoo].lancar();
        cout << "OK: voo " << codigo << " lancado\n";

    }
    void explodirVoo(int codigo){
        int posVoo = buscarVoo(codigo);
        if(posVoo == -1){
            cout << "ERRO: voo " << codigo << " nao cadastrado\n";
            return;
        }
        if(voos[posVoo].getEstado() != "em curso"){
            cout << "ERRO: voo " << codigo << " nao esta em curso\n";
            return;
        }

        for(size_t i=0; i<voos[posVoo].getQuantidadeAstronautas(); i++){
            string cpf = voos[posVoo].getCpf(i);
            astronautas[buscarAstronauta(cpf)].morrer();
        }

        voos[posVoo].explodir();
        cout << "OK: voo " << codigo << " explodiu\n"; 

    }
    void finalizarVoo(int codigo){
        int posVoo = buscarVoo(codigo);
        if(posVoo == -1){
            cout << "ERRO: voo " << codigo << " nao cadastrado\n";
            return;
        }
        if(voos[posVoo].getEstado() != "em curso"){
            cout << "ERRO: voo " << codigo << " nao esta em curso\n";
            return;
        }

        for(size_t i=0; i<voos[posVoo].getQuantidadeAstronautas(); i++){
            string cpf = voos[posVoo].getCpf(i);
            astronautas[buscarAstronauta(cpf)].desembarcar();
        }

        voos[posVoo].finalizar();
        cout << "OK: voo " << codigo << " finalizado com sucesso\n"; 

    }
    void listarVoos(){
        cout << "LISTA DE VOOS\n";
        string estados[4] = {"planejado", "em curso", "finalizado com sucesso", "finalizado com explosao"};

        for(size_t e=0; e<4; e++){
            cout << "== " << estados[e] << " ==\n";

            bool AlgumVoo = false;
            
            for(size_t i=0; i<voos.size(); i++){
                if(voos[i].getEstado() == estados[e]){
                    AlgumVoo = true;

                    cout << "Voo " << voos[i].getCodigo() << ": ";

                    int qnt = voos[i].getQuantidadeAstronautas();
                    if(qnt == 0){
                        cout << "sem astronautas\n";
                    } else{
                        for(size_t j=0; j<qnt; j++){
                            if(j>0) cout << ", ";

                            string cpf = voos[i].getCpf(j);
                            int pos = buscarAstronauta(cpf);
                            cout << cpf << " " << astronautas[pos].getNome();
                        }
                        cout << "\n";
                    }
                }
            }
            if(!AlgumVoo){
                cout << "(nenhum)\n";
            }
        }


    }
    void listarMortos(){
    cout << "ASTRONAUTAS MORTOS\n";
    bool algumMorto = false;
    for(size_t i=0; i<astronautas.size(); i++){
        if(!astronautas[i].estaVivo()){
            algumMorto = true;
            cout << astronautas[i].getCpf() << " " << astronautas[i].getNome() << " - voos: ";
            bool algumVoo = false;
            for(size_t j=0; j<voos.size(); j++){
                if(voos[j].getEstado() != "planejado" && 
                    voos[j].temAstronauta(astronautas[i].getCpf())){
                    if(algumVoo) cout << " ";
                    cout << voos[j].getCodigo();
                    algumVoo = true;
                }
            }
            if(!algumVoo){
                cout << "nenhum";
            }
            cout << "\n";
        }
    }
    if(!algumMorto){
        cout << "(nenhum)\n";
    }
    }
    void listarAstronautas(){
        cout << "LISTA DE ASTRONAUTAS\n";

        // disponiveis: vivos que nao estao em nenhum voo em curso
        cout << "== disponiveis ==\n";
        bool algum = false;
        for(size_t i=0; i<astronautas.size(); i++){
            if(!astronautas[i].estaVivo()) continue;
            bool emVoo = false;
            for(size_t j=0; j<voos.size(); j++){
                if(voos[j].getEstado() == "em curso" && voos[j].temAstronauta(astronautas[i].getCpf())){
                    emVoo = true;
                    break;
                }
            }
            if(!emVoo){
                cout << astronautas[i].getCpf() << " " << astronautas[i].getNome()
                     << " (" << astronautas[i].getIdade() << " anos)\n";
                algum = true;
            }
        }
        if(!algum) cout << "(nenhum)\n";

        // em voo: vivos em algum voo em curso
        cout << "== em voo ==\n";
        algum = false;
        for(size_t i=0; i<astronautas.size(); i++){
            if(!astronautas[i].estaVivo()) continue;
            for(size_t j=0; j<voos.size(); j++){
                if(voos[j].getEstado() == "em curso" && voos[j].temAstronauta(astronautas[i].getCpf())){
                    cout << astronautas[i].getCpf() << " " << astronautas[i].getNome()
                         << " (" << astronautas[i].getIdade() << " anos) - voo "
                         << voos[j].getCodigo() << "\n";
                    algum = true;
                    break;
                }
            }
        }
        if(!algum) cout << "(nenhum)\n";

        // mortos
        cout << "== mortos ==\n";
        algum = false;
        for(size_t i=0; i<astronautas.size(); i++){
            if(!astronautas[i].estaVivo()){
                cout << astronautas[i].getCpf() << " " << astronautas[i].getNome()
                     << " (" << astronautas[i].getIdade() << " anos)\n";
                algum = true;
            }
        }
        if(!algum) cout << "(nenhum)\n";
    }
    void historico(string cpf){
        int pos = buscarAstronauta(cpf);
        if(pos == -1){
            cout << "ERRO: astronauta " << cpf << " nao cadastrado\n";
            return;
        }
        cout << "HISTORICO DE " << astronautas[pos].getCpf() << " " << astronautas[pos].getNome() << "\n";
        bool algum = false;
        for(size_t j=0; j<voos.size(); j++){
            if(voos[j].getEstado() != "planejado" && voos[j].temAstronauta(cpf)){
                cout << "voo " << voos[j].getCodigo() << ": " << voos[j].getEstado() << "\n";
                algum = true;
            }
        }
        if(!algum) cout << "(nenhum voo)\n";
    }
};
// Depois, em cada comando, apague a linha do cout com "TODO" e descomente
// a chamada ao metodo da Agencia.

int main() {
    Agencia agencia;

    string comando;

    while (cin >> comando) {   // le uma palavra; para no FIM ou quando a entrada acaba
        if (comando == "FIM") {
            break;
        } else if (comando == "CADASTRAR_ASTRONAUTA") {
            string cpf, nome;
            int idade;
            cin >> cpf >> idade;
            getline(cin >> ws, nome);   // o nome vem por ultimo e pode ter espacos
            agencia.cadastrarAstronauta(cpf, nome, idade);

        }
        else if (comando == "CADASTRAR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.cadastrarVoo(codigo);

        } else if (comando == "ADICIONAR_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            agencia.adicionarAstronauta(cpf, codigo);
        } else if (comando == "REMOVER_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            agencia.removerAstronauta(cpf, codigo);
        } else if (comando == "LANCAR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.lancarVoo(codigo);
        } else if (comando == "EXPLODIR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.explodirVoo(codigo);
        } else if (comando == "FINALIZAR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.finalizarVoo(codigo);
        } else if (comando == "LISTAR_VOOS") {
            agencia.listarVoos();
        } else if (comando == "LISTAR_MORTOS") {
            agencia.listarMortos();
        } else if (comando == "LISTAR_ASTRONAUTAS") {
            agencia.listarAstronautas();
        } else if (comando == "HISTORICO") {
            string cpf;
            cin >> cpf;
            agencia.historico(cpf);
        } else {
            cout << "ERRO: comando desconhecido " << comando << endl;
        }
    }

    return 0;
}
