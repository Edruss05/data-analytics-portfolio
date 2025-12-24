library(tidyverse)
library(robotstxt)
library(rvest)

#====================Exercise 1=======================#
domain <- "https://air.plumelabs.com/"
paths_allowed(domain)

#====================Exercise 2=======================#
url<- "Air Quality Lexington, KY_ Live air quality and pollution Forecasts.html"
page <- read_html(url)
AQI <- page %>%
  html_elements(".pollutant-table__concentration") %>%
  html_text(trim = TRUE) %>%
  as.numeric() %>%
  head(4)
AQI

#====================Exercise 3=======================#
City <- page %>%
  html_element(".breadcrumb__item--active") %>%
  html_text(trim = TRUE)
City

#====================Exercise 4=======================#
AQIdata <- tibble(
  pm2_5 = AQI[1],
  pm10 = AQI[2],
  NO2 = AQI[3],
  O3 = AQI[4],
  City = City)
AQIdata

#====================Exercise 5=======================#
url<- "Air Quality Indianapolis, IN_ Live air quality and pollution Forecasts.html"
page <- read_html(url)
AQI <- page %>%
  html_elements(".pollutant-table__concentration") %>%
  html_text(trim = TRUE) %>%
  as.numeric() %>%
  head(4)
City <- page %>%
  html_element(".breadcrumb__item--active") %>%
  html_text(trim = TRUE)
AQIdata <- tibble(
  pm2_5 = AQI[1],
  pm10 = AQI[2],
  NO2 = AQI[3],
  O3 = AQI[4],
  City = City)
AQIdata

#====================Exercise 6=======================#
saveRDS(AQIdata, "indianapolis_aqi.rds")
