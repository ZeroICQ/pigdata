library("ggplot2")
data <- read.csv("titanic_train.csv")

died <- data[which(data$Survived == 0),]
alive <- data[which(data$Survived == 1),]

ddf <- table(died$Fare)
ddf

adf <- table(alive$Fare)
adf
ggplot(data=alive, aes(x=factor(Fare), fill=Fare))+geom_bar()
ggplot(data=died, aes(x=factor(Fare), fill=Fare))+geom_bar()
