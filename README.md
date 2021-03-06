# Victorious-war-odds-simulator
A c++, project of a Programming logic course ministred in UFBA-Brazilian university

G20 Countries war simulator
c++ project
Lucas Rabelo
Introduction to programming logic.

# **Report**

In order to create a project to the introduction to programming logic course (named formely by data processing in Federal University of Bahia-Brazil), it was proposed the creation of a war simulator, involving the G20 countries, in the beginning the goal was to use all 193 countries recognised by UN, but since it wasn’t possible to include all of them, only the G20 ones were considered to this first step of the project designed in the data processing course and  one of the goals was to use a great amount of the concepts learned in it.
 
 The EU members were not included, although the supranational organization is a remaining member of the G20, only the 19 countries were included in the simulator.
 
 A brief look in countries with the G20 membership:

Australia;
Canada;
Saudi Arabia;
US;
India;
Russia;
South Africa;
Turkey;
Argentina;
Brazil;
Mexico;
France;
Germany;
Italy;
UK;
China;
Indonesia;
Japan;
South Korea;

 The number of wars fought by each country was searched into wikipedia, using the terms following terms:”Number of wars fought by (country name)”, “Wars fought by (Country name)” and  “Battles fought by (Country name)”.


# **What’s the algorithm designed to do?**

 By using a briefly empirical evidence given by a research in the internet, amongst the wars fought by the G20 countries, the algorithm is supposed to store two countries, and calculate the odds of both countries winning a war, and then calculate this statistic for the odds of the first chosen country win a war when compared to the second one, the algorithm also calculates the confidence interval for the odds ratio, and tells if the odds ratio calculated do not have a strong significance level.

# **What’s an odds ratio?**

Usually used in epidemiological studies the odds ratio is a statistic utilized by statisticians and researchers to analyse the risk of one group exposed to some characteristic that would be interesting for the study, in comparison to another group that wasn’t exposed to that characteristic, developing a disease.

 In this project the odds ratio were adapted to calculate the odds of a country winning a war, when compared to other(Be careful: The algorithm does not calculate the odds of one country winning a war against another one, but the odds of a country winning a war when compared to another one).

The odds ratio is calculated by the following manner:

 Taking p as the likelihood of an event occurrence in the first group this measure is given by:

Having “a” as the total of events needed(in this project, the number of victories for instance), the odds of an event happening is given by:

total=not desired events+a

p1= a/total-a

For the second measure p2(second group), the calculation is similar;

So the odds ratio is given by r=p1/p2 and if:

 r=1, p1 and p2 have the same probability of occurring;

 r<1; p1 is most improbable to happen than  p2;

r>1; p1 is most probable to happen than p2;

In order to calculate the confidence interval we have:


  ci = exp(log(or) ± Zα/2 *√1/a + 1/b + 1/c + 1/d), Z is the critical value, and it's supposed to be 1,96, cause we are calculating for a 95% confidence interval

  or is the odds ratio

  a is supposed the number of the desired event in the first group
  b is supposed the number of the undesired event in the first group
  c is supposed the number of the desired event in the second group
  d is supposed the number of the undesired event in the second group


 “+” signal gives the superior part of the confidence interval, “-” gives the inferior one.

 If the 1 value is included in the confidence interval then the result isn’t significant which means one can not take much conclusions about the odds ratio.


# **Details...**

For the record, considering that countries like United States usually pick harder battles, and countries like Brazil(which only lost one war) fought easier ones when compared to the US, some results may be surprising, nuclear capacity was not considered in this version of the project, this project also supposes data normality, and it’s also important to remember that it’s really difficult to foresee the result of a war, and nowadays that goal is even harder to fulfill.
