#include<iostream>
using namespace std;

struct Note {
    int num;
    string date;     // 日期，如 2026-11-19
    string title;    // 标题
    string content;  // 内容
    Note *next;
};

int number1,number2=0;
Note* head=NULL,*temp;

int main(){
    do{

        cout<<"===== 我的记事本 ====="<<endl<<endl;
        cout<<"0. 退出"<<endl;
        cout<<"1. 添加笔记"<<endl;
        cout<<"2. 查看全部"<<endl;
        cout<<"3. 搜索"<<endl;
        cout<<"4. 删除"<<endl;
        cout<<"请选择：";
        MENU:
        cin>>number1;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1024, '\n');
            cout<<"输入错误，请重新输入。"<<endl;
            goto MENU;
        }


        switch(number1){


            case 0: break;


            case 1:{
                for(int i=0;;i++){
                    number2++;
                    temp=new Note();
                    temp->num=number2;
                    if(head==NULL){
                        temp->next=NULL;
                        head=temp;
                    }else{
                        temp->next=head;
                        head=temp;
                    }
                    cout<<"请输入日期：";
                    cin>>head->date;
                    cout<<"请输入标题: ";
                    cin>>head->title;
                    cout<<"请输入内容: ";
                    cin>>head->content;
                    cout<<endl;
                    int a=1;
                    cout<<"按1继续添加，按0退出： ";
                    FLAG1:
                    cin>>a;
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(1024, '\n');
                        cout<<"输入错误，请重新输入。"<<endl;
                        goto FLAG1;
                    }
                    if(a==0){
                        break;
                    }else if(a!=0&&a!=1){
                        cout<<"输入错误，请重新输入。"<<endl;
                        goto FLAG1;
                    }  
                }
                break;
            }


            case 2:{
                Note *p=head;
                while(p!=NULL){
                    cout<<p->num<<'.'<<" "<<p->title<<endl;
                    p=p->next;
                }
                cout<<"按1查看详情，按零退出:  ";
                FLAG2:
                int a;
                cin>>a;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(1024, '\n');
                    cout<<"输入错误，请重新输入。"<<endl;
                    goto FLAG2;
                }
                if(a==0){
                    break;
                }else if(a!=0&&a!=1){
                    cout<<"输入错误，请重新输入。"<<endl;
                    goto FLAG2;
                }else if(a==1){
                    cout<<"输入你要查看的笔记序号： ";
                    FLAG21:
                    int b;
                    cin>>b;
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(1024, '\n');
                        cout<<"输入错误，请重新输入。"<<endl;
                        goto FLAG21;
                    }
                    if(b<=0||b>number2){
                        cout<<"输入错误，请重新输入。"<<endl;
                        goto FLAG21;
                    }else{
                        Note *p=head;
                        while(p!=NULL){
                            if(p->num==b){
                                cout<<p->date<<" "<<p->content<<endl;
                                break;
                            }
                            p=p->next;
                        }
                    }
                    cout<<"按0退出。"<<endl;
                    int c;
                    while(true){
                        cin>>c;
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(1024, '\n');
                            cout<<"输入错误，请重新输入。"<<endl;
                            continue;
                        }
                        if(c==0) break;
                    }
                }
                break;
            }


            case 3:{
                cout<<"请输入关键词： ";
                string m;
                int n=0,j=0;
                int find[99];
                cin>>m;
                Note *p=head;
                while(p!=NULL){
                    bool o=(p->date.find(m)!=string::npos||p->title.find(m)!=string::npos||p->content.find(m)!=string::npos);
                    if(o){
                        n++;
                        find[j]=p->num;
                        j++;
                        cout<<p->num<<". "<<p->title<<endl;
                    }
                    p=p->next;
                }
                cout<<"=======搜索到"<<n<<"个结果。======="<<endl<<endl<<"按1查看详情，按0返回菜单。"<<endl;
                FLAG3:
                int a;
                cin>>a;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(1024, '\n');
                    cout<<"输入错误，请重新输入。"<<endl;
                    goto FLAG3;
                }
                if(a==0){
                    break;
                }else if(a!=0&&a!=1){
                    cout<<"输入错误，请重新输入。"<<endl;
                    goto FLAG3;
                }else if(a==1){
                    cout<<"输入你要查看的笔记序号： ";
                    FLAG31:
                    int b;
                    cin>>b;
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(1024, '\n');
                        cout<<"输入错误，请重新输入。"<<endl;
                        goto FLAG31;
                    }
                    if(b<=0||b>number2){
                        cout<<"输入错误，请重新输入。"<<endl;
                        goto FLAG31;
                    }else{
                        Note *p=head;
                        while(p!=NULL){
                            if(p->num==b){
                                cout<<p->date<<" "<<p->content<<endl;
                                break;
                            }
                            p=p->next;
                        }
                    }
                    cout<<"按0退出。"<<endl;
                    int c;
                    while(true){
                        cin>>c;
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(1024, '\n');
                            cout<<"输入错误，请重新输入。"<<endl;
                            continue;
                        }
                        if(c==0) break;
                    }
                }
                break;
            }


            case 4:{
                if(number2==0){
                    cout<<"记事本里还没有笔记，无法删除。"<<endl;
                    break;
                }
                FLAG4:
                cout<<"输入你要删除的笔记序号： ";
                int a;
                cin>>a;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(1024, '\n');
                    cout<<"输入错误，请重新输入。"<<endl;
                    goto FLAG4;
                }
                if(a>0&&a<=number2){
                    Note *p=head;
                    if(p->num==a){
                        head=p->next;
                        delete p;
                        p=NULL;
                        number2--;
                    }
                    while(p!=NULL){
                        if(p->num==a+1){
                            number2--;
                            Note *n=p;
                            p=p->next;
                            n->next=p->next;
                            delete p;
                            p=head;
                            while(p!=NULL&&p->num>a){
                                p->num--;
                                p=p->next;
                            }
                            break;
                        }
                        p=p->next;
                    }
                    Note *k=head;
                    while(k!=NULL){
                        cout<<k->num<<'.'<<" "<<k->title<<endl;
                        k=k->next;
                    }
                    cout<<endl;
                    if(number2==0){
                        cout<<"你已经删尽了。";
                        break;
                    }
                    cout<<"按1继续删除，按0退出： ";
                    FLAG41:
                    int b;
                    cin>>b;
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(1024, '\n');
                        cout<<"输入错误，请重新输入。"<<endl;
                        goto FLAG41;
                    }
                    if(b==0){
                        break;
                    }else if(b!=0&&b!=1){
                        cout<<"输入错误，请重新输入。"<<endl;
                        goto FLAG41;
                    }else if(b==1){
                        goto FLAG4;
                    }
                }else{
                    cout<<"输入错误，请重新输入。"<<endl;
                    goto FLAG4;
                }
            }
            default: cin.clear();cin.ignore(1024, '\n');cout<<"输入错误，请重新输入。"<<endl;
        }
    }while(number1!=0);
    return 0;
}