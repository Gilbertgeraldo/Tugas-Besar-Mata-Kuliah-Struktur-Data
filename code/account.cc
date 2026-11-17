#include<iostream>
#include "../header/adt.h"
#include "../header/account.h"

void accountCreateList(ListAccount *list){
    list->first = nullptr;
}

adrAccount accountAllocate(string username,string password,AccountRole Role){
    adrAccount p = new elmAccount;
    p->info.username = username;
    p->info.password = password;
    p->info.role = Role;
    p->info.matchesPlayed = 0;
    p->info.wins = 0;
    p->info.losses = 0;
    p->info.kills = 0;
    p->info.deaths = 0;

    p->team.first = nullptr;
    p->history.last = nullptr;
    p->team.size = 0;

    p->history.first = nullptr;
    p->history.last = nullptr;

    p->nextMatchNumber = 1;
    p->next = nullptr;
    return p;
}

void accountDeallocate(adrAccount &node){
    if(node == nullptr){
        return;
    }
    adrMember m = node->team.first;
    while(m != nullptr){
        adrMember nextMember = m->next;

        adrWaypoint w = m->state.steps.first;
        while(w != nullptr){
            adrWaypoint nextStep = w->next;
            w->next = nullptr;
            w = nextStep;
        }
        m->state.steps.first = nullptr;
        m->state.steps.last = nullptr;
        
        m->next = nullptr;
        m->prev = nullptr;

        m = nextMember;
    }
    node->team.first = nullptr;
    node->team.last = nullptr;
    node->team.size = 0;

    adrMatch r = node->history.first;
    while(r != nullptr){
        adrMatch nextMatch = r->next;
        r->next = nullptr;
        r->prev = nullptr;
        r = nextMatch;
    }
    node->history.first = nullptr;
    node->history.last = nullptr;

    node->next = nullptr;
    node = nullptr;
}

void accountInsertLast(ListAccount &list,adrAccount node){
    if(node == nullptr){
        return;
    }
    adrMember m = node->team.first;
    while(m != nullptr){
        adrMember nextMember = m->next;

        adrWaypoint w = m->state.steps.first;
        while(w != nullptr){
            adrWaypoint nextStep = w->next;
            w->next = nullptr;
            w = nextStep;
        }
        m->state.steps.first = nullptr;
        m->state.steps.last = nullptr;

        m->next = nullptr;
        m->prev = nullptr;
        m = nextMember;
    }
    node->team.first = nullptr;
    node->team.last = nullptr;
    node->team.size = 0;
    

    adrMatch r = node->history.first;
    while(r != nullptr){
        adrMatch nextMatch = r->next;
        r->next = nullptr;
        r->prev = nullptr;
        r =  nextMatch;
    }
    node->history.first = nullptr;
    node->history.last = nullptr;

    node->next = nullptr;
    node = nullptr;
}

void accountDeleteFirst(ListAccount &list,adrAccount &node){
    if(node == nullptr){
        return;
    }
    node = list.first;
    if(node != nullptr){
        list.first = node->next;
        node->next = nullptr;
    }
}

void accountDeleteAfter(ListAccount &list,adrAccount prec,adrAccount &node){
    node = nullptr;
    if(prec != nullptr && prec->next != nullptr){
        node = prec->next;
        prec->next = node->next;
        node->next = nullptr;
    }
}

adrAccount accountFind(ListAccount list,string username){
    for(adrAccount curr = list.first;curr != nullptr;curr = curr->next){
        bool isSame = true;
        int i = 0;
        while(isSame && (curr->info.username[i] != '\0' || username[i] != '\0')){
            char a = curr->info.username[i];
            char b = username[i];
            if(a >= 'A' && a <= 'Z'){
                a = a - 'A' + 'a';
            }
            if(b >= 'A' && b <= 'Z'){
                b = b - 'A' + 'a';
            }
            if(a != b){
                isSame = false;
            }
            ++i;
        }
        if(isSame){
            return curr;
        }
    }
    return nullptr;
}

adrAccount accountFindPrev(ListAccount list,adrAccount target){

}

int accountCount(ListAccount list){
    adrAccount temp = list.first;
    int tot = 0;
    while(temp != nullptr){
        temp = temp->next;
        tot++;
    }
    return tot;
}

int accountCountAdmins(ListAccount list){
    adrAccount temp = list.first;
    int tot = 0;
    while(temp != nullptr){
        if(temp->info.role == ACCOUNT_ADMIN){
            tot++;
        }
        temp = temp->next;
    }
    return tot;
}

void accountPrint(ListAccount list){
    if(list.first == nullptr){
        cout << "Belum ada akun." << endl;
        return;
    }

    cout << "No\tUsername\tRole\tMain\tMenang\tKalah" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    adrAccount temp = list.first;
    int no = 1;
    while(temp != nullptr){
        cout << no << "\t";
        cout << temp->info.username << "\t\t";

        if(temp->info.role == ACCOUNT_ADMIN){
            cout << "Admin\t";
        }else{
            cout << "Pemain\t";
        }

        cout << temp->info.matchesPlayed << "\t";
        cout << temp->info.wins << "\t";
        cout << temp->info.losses << endl;

        ++no;
        temp = temp->next;
    }
}

void accountClear(ListAccount &list){
    adrAccount removed;
    while(list.first != nullptr){
        accountDeleteFirst(list,removed);
        accountDeallocate(removed);
    }
}

adrAccount accountAuthenticate(ListAccount list,string username,string password){
    adrAccount p = accountFind(list,username);
    if(p != nullptr && p->info.password == password){
        return p;
    }
    return nullptr;
}

adrAccount accountLogin(ListAccount list){
    string username,password;
    int ck = 1;
    while(ck <= 3){
        cout << "===LOGIN(Percobaan " << ck << "/3) ===" << endl;
        cout << "Username : ",cin >> username;
        cout << "Password: ",cin >> password;

        adrAccount akun = accountAuthenticate(list,username,password);
        if(akun != nullptr){
            cout << "Selamat datang, " << akun->info.username << "!" << endl;
            return akun;
        }
        cout << "Username atau password salah" << endl;
        ck++;
    }
    cout << "Gagal login 3 kali. Kembali ke Menu Awal." << endl;
    return nullptr;
}

bool accountIsUsernameValid(ListAccount list,string username){
    int len = 0;
    while(username[len] != '\0'){
        len++;
    }
    if(len < 3 || len > 15){
        cout << "Username harus 3-15 karakte." << endl;
        return false;
    }

    for(int i = 0;i < len;++i){
        char c = username[i];
        bool h = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
        bool a = (c >= '0' && c <= '9');
        if(!h && !a){
            cout << "Username tidak boleh mengandung spasi atau simbol." << endl;
            return false;
        }
    }

    if(accountFind(list,username) != nullptr){
        cout << "Username sudah dipakai." << endl;
        return false;
    }
    return true;
}

bool accountIsPasswordValid(string password,string confirmation){
    int len = 0;
    while(password[len] != '\0'){
        len++;
    }
    if(len < 6){
        cout << "Panjang minimal 6 karakter" << endl;
        return false;
    }
    if(password != confirmation){
        cout << "Konfirmasi password tidak sama." << endl;
        return false;
    }
    return true;
}

bool accountRegister(ListAccount &list,AccountRole role){
    string username,password,confirm;
    cout << "====== REGISTER ======" << endl;
    cout << "Username :",cin >> username;
    cout << "Password : ",cin >> password;
    cout << "Konfirmasi password kamu :",cin >> confirm;
    if(!accountIsPasswordValid(password,confirm)){
        return false;
    }
    adrAccount p = accountAllocate(username,password,role);
    accountInsertLast(list,p);
    if(role == ACCOUNT_ADMIN){
        cout << "Akun admin berhasil ditambahkan." << endl;
    }else{
        cout << "Registrasi berhasil,silahkan login." << endl;
    }
    return true;
}

bool accountRemove(ListAccount &list,adrAccount target,adrAccount current){
    if(target == nullptr){
        cout << "Akun tidak ditemukan." << endl;
        return false;
    }

    if(target == current){
        cout << "Tidak bisa menghapus akun sendiri." << endl;
        return false;
    }
    
    if(target->info.role == ACCOUNT_ADMIN && accountCountAdmins(list) == 1){
        cout << "Tidak bisa menghapus admin terakhir." << endl;
        return false;
    }

    adrAccount removed;
    if(target == list.first){
        accountDeleteFirst(list,removed);
    }else{
        adrAccount prec = accountFindPrev(list,target);
        accountDeleteAfter(list,prec,removed);
    }
    accountDeallocate(removed);
    cout << "Akun berhasil dihapus." << endl;
    return true;   
}