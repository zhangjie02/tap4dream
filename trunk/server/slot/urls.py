from django.conf.urls import patterns, include, url

from django.contrib import admin
admin.autodiscover()

from API import api

urlpatterns = patterns('',
    # Examples:
    url(r'^$', api),
    # url(r'^blog/', include('blog.urls')),

    #url(r'^admin/', include(admin.site.urls)),
)
