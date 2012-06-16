class FishImpl;
class Subject;

enum FishType {GOLD, SALMON};

class FishFactory{

public:
	static FishImpl* create(FishType fishType);
	static FishImpl* create(Subject* subject, FishType fishType);

protected:
	FishFactory();
	FishFactory(const FishFactory& fishFactory);
	FishFactory& operator=(const FishFactory& fishFactory);

private:

};