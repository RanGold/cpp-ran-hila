#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;
enum Action;

class Observer {
public:
	Observer(Subject*);
	virtual ~Observer() {}
	
	void clearSubject();
    virtual void update(const Subject*, Action) = 0;

protected:
	Subject* _subject;

private:
	Observer(const Observer&);
	Observer& operator=(const Observer&);
};

#endif