#include<iostream>
#include<string>
using namespace std;

struct Note {
    string date;     // 日期，如 2026-11-19
    string title;    // 标题
    string content;  // 内容
};

int main(){
    int a=1,b=0;
    Note notes[100]; // 假设最多存储100条笔记
    for(int i=0;;i++){
        cout<<"===== 我的记事本 ====="<<endl<<endl;
        cout<<"0. 退出"<<endl;
        cout<<"1. 添加笔记"<<endl;
        cout<<"2. 查看全部"<<endl;
        cout<<"3.查看详情"<<endl;
        cout<<"4. 搜索"<<endl;
        cout<<"5. 删除"<<endl;
        cout<<"请选择：";
        cin>>a;
        switch(a){
            case 0:
                cout<<"退出"<<endl;
                break;
            case 1:{
                cout<<"=====添加笔记====="<<endl;
                int d=1;
                while(d>0){
                    cout<<"请输入日期（如2026-11-19）：";
                    cin>>notes[b].date;
                    cout<<endl;
                    cout<<"请输入标题：";
                    cin>>notes[b].title;
                    cout<<endl;
                    cout<<"请输入内容：";
                    cin>>notes[b].content;
                    cout<<endl;
                    b++;
                    cout<<"是否继续添加？（1.是 0.否）：";
                    cin>>d;
                    if(d!=1 && d!=0){
                        cout<<"输入错误，请重新输入！"<<endl;
                    }
                }
                break;
            }
            case 2:{
                cout<<"=====查看全部====="<<endl;
                for(int i=0;i<b;i++){
                    cout<<i+1<<'.'<<" "<<"日期："<<notes[i].date<<" ";
                    cout<<"标题："<<notes[i].title<<endl;
                }
                for(;;){
                    int e;
                    cout<<"0.返回菜单 1.查看详情"<<endl;
                    cout<<"请选择：";
                    cin>>e;
                    if(e==0){
                        break;
                    } else if (e==1){
                        goto case3;
                    } else if (e!=0 && e!=1){
                        cout<<"输入错误，请重新输入！"<<endl;
                    }
                }
                break;
            }
            case 3:{
                case3:
                cout<<"=====查看详情====="<<endl;
                int c;
                cout<<"请输入要查看的笔记编号：";
                cin>>c;
                if(c>0 && c<=b){
                    cout<<c<<'.'<<" "<<"日期："<<notes[c-1].date<<" ";
                    cout<<"标题："<<notes[c-1].title<<" ";
                    cout<<"内容："<<notes[c-1].content<<endl;
                } else {
                    cout<<"无效的笔记编号！"<<endl;
                    goto case3;
                }
                cout<<"按0返回菜单,按1继续查看。"<<endl;
                int f;
                FLAG:
                cin>>f;
                if(f==0){
                    break;
                } else if (f==1){
                    goto case3;
                } else {
                    cout<<"输入错误，请重新输入！"<<endl;
                    goto FLAG;
                }
                break;
            }
            case 4:{
                cout<<"=====搜索====="<<endl;
                cout<<"请输入要搜索的关键字：";
                string keyword;
                cin>>keyword;
                int found = 0;
                int foundnumbers[100]={0}; // 用于存储找到的笔记编号
                int j=0;
                void searchnotes(int found,int foundnumbers[],int b,int &j,string keyword,Note notes[]);
                searchnotes(found,foundnumbers,b,j,keyword,notes);
                cout<<"搜索到"<<j<<"个结果。"<<endl;
                for(int i=0;i<j;i++){
                    cout<<foundnumbers[i]<<'.'<<" "<<"日期："<<notes[foundnumbers[i]-1].date<<" ";
                    cout<<"标题："<<notes[foundnumbers[i]-1].title<<" ";
                }
                cout<<"按0返回菜单，按1查看详情。"<<endl;
                int g;
                cin>>g;
                if(g==0){
                    break;
                } else if (g==1){
                    goto case3;
                } else {
                    cout<<"输入错误，请重新输入！"<<endl;
                    goto FLAG;
                }
                break;
            }
            case 5:{
                cout<<"=====删除====="<<endl;
                FLAG2:
                cout<<"请选择要删除的序号："<<endl;
                int h;
                cin>>h;
                if(h>0&&h<=b){
                    for(int i=h-1;i<b-1;i++){
                        notes[i]=notes[i+1];
                    }
                    b--;
                    for(int i=0;i<b;i++){
                    cout<<i+1<<'.'<<" "<<"日期："<<notes[i].date<<" ";
                    cout<<"标题："<<notes[i].title<<endl;
                    }
                    cout<<"按0返回菜单，按1继续删除。"<<endl;
                    int l;
                    cin>>l;
                    if(l==1)
                    goto FLAG2;
                    else if(l!=1&&l!=0)
                    cout<<"输入错误，请重新输入！"<<endl;
                }
                break;
            }
            default:
                cout<<"输入错误，请重新输入！"<<endl<<endl;
        }
        if(a==0){
            break;
        }
    }
    return 0;
}

void searchnotes(int found,int foundnumbers[],int b,int &j,string keyword,Note notes[]){
    for(int i=0;i<b;i++){
        bool k = false;
        k=(notes[i].date.find(keyword)!=string::npos||notes[i].title.find(keyword)!=string::npos||notes[i].content.find(keyword)!=string::npos);
        if(k){
        foundnumbers[j]=i+1;
        j++;
        }
    }
}