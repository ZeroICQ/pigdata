# Каковы медиана и стандартное отклонение платежей
# (Fare)? Округлите до 2 десятичных знаков.
library("ggplot2")
data <- read.csv("titanic_train.csv")

dev <- round(sd(data$Fare), digits = 2)
med <- round(median(data$Fare), digits = 2)
common <- data.frame(dev, med)
mm <- t(common)
qplot(common) + xlim(1000) + ylim(100)