/*
	객체 관계

	- Composiotion(구성) part-of : 전체, 부품, 생명주기 공유

	- Aggregation(집합) has-a : 생명주기 공유 X

	- Association(연계) uses-a : 다른 클래스의 참조변수 사용, 좋은 방식이라 볼수 없음

	- Dependency(의존) depend-on : 잠깐 가져다 씀 

	++ Inheritance(상속) is-a

	                                  관계 형태    다른 클래스에 속할수 있는가  멤버의 존재를 클래스가 관리  방향성
   Composition(구성)     part-of     전체/부품                   No                        Yes             단방향
   Aggregation(집합)     has-a       전체/부품                   Yes                       No              단방향
   Association(연계)     uses-a      용도 외엔 무관              Yes                       No              단방향 or 양방향
   Dependency(의존)      depends-on  옹도 외엔 무관              Yes                       Yes             단방향
*/

/*
	결합도 낮추고
	응집도 올린다
*/