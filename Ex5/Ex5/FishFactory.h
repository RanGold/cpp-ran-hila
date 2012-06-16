class FishImpl;

enum FishType {GOLD, SALMON};

class FishFactory{

public:
	static FishImpl* create(FishType fishType);

protected:
	FishFactory();
	FishFactory(const FishFactory& fishFactory);
	FishFactory& operator=(const FishFactory& fishFactory);

private:

};