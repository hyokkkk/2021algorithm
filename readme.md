# 2021 spring algorithm
## 210302 OT
- 책
    - Introduction to Algorithms. 너무 방대해요. 학부과정에선 앞부분을 좀 강의하고, 대학원은 뒷부분이 많이 사용됩니다. 이 책 구할 수 있으면 구하는 게 좋고, 그 외에도 알고리즘 텍스트북이 많이 있어요. 이게 기본적으로 방대하기때문에 한학기용 책이 많이 있다. 문병로샘이 쓰신 쉽게 배우는 알고리즘. 문병로샘의 그 책도 intro에 기반해서 만들어진 책이에요. 이 두 책 중에 하나를 구입하면 될 것 같고, 내가 만든 강의안은 이 두 책에 기반을 두고 있어요. 기본적으로는 문병로샘 따라가면서, 그 중에서 상당부분은 intro도 들어있고. ㅇㅇ 그렇게 만들어진 강의안입니다. 강의 내용을 보면 제일먼저,

1. 알고리즘이라는 것은 correctness예요. 내가 짠 프로그램이 맞게 돌아야 하는 거죠. 그 다음에 중요한 것이 complexity analysis. 빠르기가 어케 되느냐.
    - 그런 다음에는 여러 알고리즘을 배우게 될 것입니다. 마지막에는 아주 중요한 개념인 np를 다룬다. 
1. 그래서 학부 알고리즘 강의라는 것은 대개는 내용이 비슷해요. 
1. 중간기말은 총점 120만점. 시험준비물도 같이 제출한다. 5점 만점으로. 시험은 되도록이면 모여서 볼 수 있으면 좋은데, 상황 보면서 진행합시다. 
1. 숙제는 3개정도 나갈 겁니다. 숙제는 각각 50점만점. 제출 마감일이 지나고나면 하루에 3점씩 감점. 일주일 지나면 안 받아요. 
    - 숙제 카피 있는지 검사할 겁니다. 카피 발견 시 한 사람도 그렇고 보여준 사람도 그렇고 다 0점을 받게 돼있어요. 카피가 발견되면 무조건 0점입니다. 
1. 그담에 출석점수가 있는데, 예전에는 이렇게 했는데 출석점수는 약간 좀 다르게 해야할 것 같아요. 보너스도 강의실에서 할 때는 대답 잘하든지, 좋은 질문하면 보너스를 줬는데 비대면은 이것도 쉽지가 않을 것 같아요. 
1. 재수강은 최대 a-입니다. 
1. 중간/기말 4월 말/ 6월 초순. 진도 나가는 거 보면서 결정할거예요. 
1. 과제는 코딩과제입니다. 프로그래밍 언어는 상관 없어요. 
1. 반영비율은 셤 : 125점 만점. 숙제는 150만점. 출석 좀 있고.. 이정도로 전체가 구성됩니다. 

## ch01. what is algorithm
- 알고리즘이 무엇인지
- 알골을 배우는 이유
    1. 절차적 사고방식
    1. abstraction

- 오늘은 여기까지~~~~

## 210304 목. 알고리즘 분석 방법론
- 오늘 배울 것: 알고리즘... 알고리즘을 어케 분석하는지, symptotic notation 배우게 된다. 

### 알고리즘 증명
1. loop있는 알고리즘은 loop invariant 통해서 증명할 수 있다. 
1. 알고리즘이 terminate하는 것을 보인다.
1. 올바른 결과로 terminate 함을 보인다.

## 210309
우리가 insertion sort를 만들 때 만드는 사람이 저 개념을 가지고 알고리즘을 만든거였거든요. loop invariant라는 건 알고리즈믕ㄹ 만들 때 막연히 가지고 있던 생각을 구체화시키는 거. 세 단계를 거쳐서 증명을 하게 된다는 거죠. 