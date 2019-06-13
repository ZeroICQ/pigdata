# Каковы медиана и стандартное отклонение платежей
# (Fare)? Округлите до 2 десятичных знаков.
library("ggplot2")
data <- read.csv("titanic_train.csv")

dev <- round(sd(data$Fare), digits = 2)
med <- round(median(data$Fare), digits = 2)
cm <- c(dev, med)

qplot(c("dev", "med"), cm)