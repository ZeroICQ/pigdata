library("ggplot2")
data <- read.csv("titanic_train.csv")
m <- data$Sex
plot(m, geom="histogram")
# qplot(factor(m), m, geom = "histogram") 
