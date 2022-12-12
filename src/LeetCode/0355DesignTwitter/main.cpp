#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <functional>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"
#include "TestStepBase.hpp"

class Twitter {
public:
    Twitter() { 
         
    } 
     
    void postTweet(int userId, int tweetId) { 
        // add tweetId to list 
        if (this->mUserData.find(userId) != this->mUserData.end()) {  
            this->mUserData[userId].Tweets.push_front(Tweet(this->mNumTweet, tweetId)); 
            this->mNumTweet++;  
        } 
        else { 
            UserData user; 
            this->mUserData.insert(std::pair<int, UserData>(userId, user)); 
            this->mUserData[userId].Tweets.push_front(Tweet(this->mNumTweet, tweetId)); 
            this->mNumTweet++;  
        } 
    } 
     
    std::vector<int> getNewsFeed(int userId) { 
        // iterate list and find most recent followeeId tweetId 
        std::vector<int> ret; 
        if (this->mUserData.find(userId) != this->mUserData.end()) {  
            std::priority_queue<Tweet, std::vector<Tweet>, std::function<bool(Tweet, Tweet)>> pq(Tweet::Compare);

            // put user's tweets into queue 
            for (auto const& t : this->mUserData[userId].Tweets) { 
                pq.push(t); 
            } 
             
            // put tweets of user's followee into queue 
            for (auto it = this->mUserData[userId].FollowingList.begin(); it != this->mUserData[userId].FollowingList.end(); it++){ 
                if (this->mUserData.find(*it) != this->mUserData.end()) { 
                    for (auto const& t : this->mUserData[*it].Tweets) { 
                        pq.push(t); 
                    } 
                } 
            }  
            for (int count = 0; count < 10 && !pq.empty(); count++) { 
                Tweet cur = pq.top(); 
                ret.push_back(cur.Id); 
                pq.pop(); 
            } 
        } 
        return ret; 
    } 
     
    void follow(int followerId, int followeeId) { 
        // add followeeId to followerId's list 
        if (this->mUserData.find(followerId) == this->mUserData.end()) { 
            UserData user; 
            user.FollowingList.insert(followeeId); 
            this->mUserData.insert(std::pair<int, UserData>(followerId, user)); 
        } 
        else{ 
            this->mUserData[followerId].FollowingList.insert(followeeId); 
        } 
    } 
     
    void unfollow(int followerId, int followeeId) { 
        // remove followeeId to followerId's list 
        if (this->mUserData.find(followerId) != this->mUserData.end()) { 
            int i = 0; 
            this->mUserData[followerId].FollowingList.erase(followeeId); 
        } 
    } 
private: 
    struct tweet 
    { 
        int Order = 0; 
        int Id = 0;

        tweet(int order, int id): Order(order), Id(id) 
        { 
        }

        static bool Compare(tweet l, tweet r) 
        { 
            return l.Order < r.Order; 
        } 
    }; 
    typedef struct tweet Tweet;

    struct userData 
    { 
        std::set<int> FollowingList; 
        std::list<Tweet> Tweets; 
    }; 
    typedef struct userData UserData;

    std::map<int, UserData> mUserData; 
    int mNumTweet = 0;    
};
/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

class TestTwitter : TestStepBase
{
public:
	TestTwitter()
	{}

	~TestTwitter()
	{}
	
	void Example1()
	{
		std::vector<std::string> inputStep({"Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"});
		PrintVector<std::string>(inputStep);
		std::vector<std::vector<std::string>> params({{}, {"1", "5"}, {"1"}, {"1", "2"}, {"2", "6"}, {"1"}, {"1", "2"}, {"1"}});
		std::vector<std::string> answer({"null", "null", "[5]", "null", "null", "[6, 5]", "null", "[5]"});

		Twitter* obj = nullptr;
		std::vector<std::string> result = this->ExecuteScript((void**)&obj, inputStep, params);
		PrintVector<std::string>(result);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, answer));
		if(obj)
		{
			delete obj;
			obj = nullptr;
		}
	}

protected:
	virtual std::string ConductMethod(void** obj, std::string method, std::vector<std::string> param) override
	{
		std::string ret;
		if("Twitter" == method){
			*obj = (void*)(new Twitter());
			ret = "null";
		}
		else if("postTweet" == method){
			int userId = std::stoi(param.at(0));
            int tweetId = std::stoi(param.at(1));
			((Twitter*)*obj)->postTweet(userId, tweetId);
            ret = "null";
		}
		else if("getNewsFeed" == method){
            int userId = std::stoi(param.at(0));
			std::vector<int> r = ((Twitter*)*obj)->getNewsFeed(userId);
			ret = Vector2Str(r);
		}
		else if("follow" == method){
            int followerId = std::stoi(param.at(0));
            int followeeId = std::stoi(param.at(1));
			((Twitter*)*obj)->follow(followerId, followeeId);
            ret = "null";
		}
		else if("unfollow" == method){
            int followerId = std::stoi(param.at(0));
            int followeeId = std::stoi(param.at(1));
			((Twitter*)*obj)->unfollow(followerId, followeeId);
			ret = "null";
		}

		return ret;
	}

private:

};

int main(int argc, char** argv)
{
	TestTwitter test;
	test.Example1();
	getchar();
	return EXIT_SUCCESS;
}