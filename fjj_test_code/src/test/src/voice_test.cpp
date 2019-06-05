#include<ros/ros.h>
#include<std_msgs/String.h>
#include<vector>
#include<string.h>
#include<map>
using namespace std;

map<int,string>voice_map;

void stringSplit(string s,char splitchar,vector<string>& vec){
    if(vec.size()>0)
        vec.clear();
    int length=s.length();
    int start=0;
    for(int i=0;i<length;i++){
        if(s[i]==splitchar && i==0)
            start+=1;
        else if(s[i]==splitchar){
            vec.push_back(s.substr(start,i-start));
            start=i+1;
        }
        else if(i==length-1){
            vec.push_back(s.substr(start,i+1-start));
        }
    }
}
void clear_str(string & datastr)
{
    for(int i=0;i<datastr.length();i++)
    {
         if(datastr[i]>='a'&&datastr[i]<='z'||datastr[i]>='A'&&datastr[i]<='Z'||datastr[i]==' ')
         {
             if(datastr[i]>='A'&&datastr[i]<='Z')
             {
                 datastr[i] = datastr[i] - 'A' + 'a';//小写化
             }
             continue;
         }
         else 
         {
             datastr.erase(i,1);
         }
    }
}
bool in_the_string(string words,string target)
{
    std::vector<string> res;
    clear_str(target);
    stringSplit(target,' ',res);
    for(int i=0;i<res.size();i++)
    {cout<<res[i]<<endl;}
    std::vector<string>::iterator result = find(res.begin(),res.end(),words);
    if(result==res.end())
    {
        cout<<"NO"<<endl;
        return false;
    }
    else
    {
        cout<<"YES"<<endl;
        return true;
    }
}
void subCallback(const std_msgs::String::ConstPtr & msg)
{

    string ss = msg->data;
    in_the_string("want",ss);

}
int main(int argc, char *argv[])
{
    ros::init(argc, argv, "voice_test");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("voiceWords", 1000, subCallback);
    ros::spin();
    return 0;
}