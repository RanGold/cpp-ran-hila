#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;

class Observer {
public:
	Observer(Subject*);
	virtual ~Observer() {}
	
	void clearSubject();
    virtual void update(const Subject*, int) = 0;

protected:
	Subject* _subject;

private:
	Observer& operator=(const Observer&);
};

#endif