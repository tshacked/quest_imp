#ifndef ___Singleton_H__
#define ___Singleton_H__

class SingleMgr
{
public:
	static SingleMgr& instance()
	{
		static SingleMgr instance;
		return instance;
	}
protected:
	SingleMgr() {}						//ctor
	SingleMgr(SingleMgr const&);      // copy ctor -	 Don't Implement
	void operator=(SingleMgr const&); // assignment op - Don't implement
};

#endif